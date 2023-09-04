class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi=0;
        vector<int>dp(n,1);
        vector<int>count(n,1);
        for(int i=0;i<n;i++){
            for(int j = 0; j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                }else if(nums[i]>nums[j] && dp[i] == dp[j]+1){
                count[i] += count[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int no =0;
        for(int i=0;i<n;i++){
            if(maxi == dp[i]){
                no+=count[i];
            }
        }
        return no;
        
    }
};