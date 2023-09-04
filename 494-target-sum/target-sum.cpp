class Solution {
public:
    int f(int index, int sum, int target,int n,int t,vector<int>& nums, vector<vector<int>> &dp){
       if(index == n){
           dp[index][sum] = (sum == target);
           return sum == target;
       }
       if(dp[index][sum] !=-1) return dp[index][sum];
       int pick = 0;
       if(sum+nums[index] <= target)
       pick += f(index+1,sum+nums[index],target,n,t,nums,dp);
       int notPick = f(index+1,sum,target,n,t,nums,dp);
       return dp[index][sum] = pick+notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int t = 0;
        for(auto it:nums){
            t+=it;
        }
       if((t-target)%2!=0 || (t-target)<0) return 0;
       vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
       return f(0,0,(t-target)/2,n,t,nums,dp);
    }
};