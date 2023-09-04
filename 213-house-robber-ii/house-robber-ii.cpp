class Solution {

 int robAlternative(vector<int> &nums,int index,vector<int> &dp){
     int n = nums.size();
     if(n == 0) {
         dp[index] = 0;
         return 0;
     }
     if(n == 1) {
         dp[index] = nums[0];
         return nums[0];
     }
     if(index == n){ 
          dp[index] = 0;
         return 0;
         }
     if(dp[index]!=-1) return dp[index];
     int pick = 0;
     int notpick = 0;
     pick = nums[index];
     if(index+2<=n)
     pick  += robAlternative(nums,index+2,dp);
     notpick += robAlternative(nums,index+1,dp);
     return  dp[index] =  max(pick,notpick);
 }

public:
    int rob(vector<int>& nums) {
       int n = nums.size();
        vector<int> temp1,temp2;
        
        if(n ==1)
        {
         temp1 = nums;
         temp2 = nums; 
        }   
        else{    
             for(int i = 0;i<n;i++){
                if(i != 0)
                temp1.push_back(nums[i]);
                if(i != n-1)
                temp2.push_back(nums[i]);
             }
        }
        vector<int> dp1(temp1.size()+1,-1);
        vector<int> dp2(temp2.size()+1,-1);

        return max(robAlternative(temp1,0,dp1),robAlternative(temp2,0,dp2));
    }
};