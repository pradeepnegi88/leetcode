class Solution {
public:
    long f(int index,int buy,vector<int>& prices, int n,vector<vector<int>> &dp,int fee){

            if(index >= n){
                return 0;
            }
            if(dp[index][buy]!=-1)return dp[index][buy];
            if(buy){
            return dp[index][buy]=max(-prices[index]+f(index+1,0,prices,n,dp,fee),f(index+1,1,prices,n,dp,fee));

            }else{
            return dp[index][buy] = max(prices[index]-fee+f(index+1,1,prices,n,dp,fee),f(index+1,0,prices,n,dp,fee));
        }
        }

 
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
         // vector<vector<int>> dp(n+1,vector<int>(2,-1));
            //   return f(0,1,prices,n,dp,fee);
            vector<vector<int>> dp(n+1,vector<int>(2,0));
                for(int index = n;index>=0;index--){
                    for (int buy=1;buy>=0;buy--){
                        if(index >= n){
                                dp[index][buy]= 0;
                                continue;
                            }
                            if(buy){
                            dp[index][buy]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                            continue;
                            }else{
                            dp[index][buy] = max(prices[index]-fee+dp[index+1][1],dp[index+1][0]);
                            continue;
                        }

                    }
                }
            return dp[0][1];
        
    }
};