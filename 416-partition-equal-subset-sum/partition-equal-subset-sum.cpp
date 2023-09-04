class Solution {
public:
    // bool f(int index,int sum,int n,int tsum,vector<int> &nums, vector<vector<int>> &dp){
      
    //     if(index == n){
    //        return sum == tsum-sum;
    //     }
    //     if(dp[index][sum]!=-1) return dp[index][sum];
    //      bool pick = false;
    //      if(nums[index]<=tsum-sum+nums[index])
    //      pick = f(index+1,sum+nums[index],n,tsum,nums,dp);
    //      bool notPick = f(index+1,sum,n,tsum,nums,dp);
    //      return dp[index][sum] = pick || notPick;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tsum  = 0;
        for(auto it:nums){
            tsum+= it;
        }
         if (tsum % 2 != 0) {
        return false; // If the total sum is odd, cannot partition into two equal subsets
         }
          //vector<vector<int>>dp(n+1,vector<int>(tsum+1,-1));
        // return f(0,0,n,tsum,nums,dp);
        // vector<vector<bool>>dp(n+1,vector<bool>(tsum+1,0));
        vector<bool>curr(tsum+1,0);
        vector<bool>next(tsum+1,0);

        for(int index = n;index>=0;index--){
            for (int sum = 0; sum<=tsum;sum++){
                if(index == n){
                    curr[sum]= (sum == tsum-sum);
                    continue;
                }
                bool pick = false;
                if(nums[index]<=tsum-(sum+nums[index]))
                pick = next[(sum+nums[index])];
                bool notPick = next[sum];
                curr[sum] = pick || notPick;
            }
            next = curr;
        }
        return curr[0];
    }
};