class Solution {




public:
        int f(int index,int buy,vector<int>& prices, int n,vector<vector<vector<int>>> &dp,int times){

            if(index == n || times == 2){
                return dp[index][buy][times]=0;
            }
            if(dp[index][buy][times]!=-1)return dp[index][buy][times];
            if(buy){
            return dp[index][buy][times]=max(-prices[index]+f(index+1,0,prices,n,dp,times),f(index+1,1,prices,n,dp,times));
            }else{
            return dp[index][buy] [times]= max(prices[index]+f(index+1,1,prices,n,dp,times+1),f(index+1,0,prices,n,dp,times));
            }
        }
    int maxProfit(vector<int>& prices) {
        // Write your code here.
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    // return f(0,1,prices,n,dp,0);
    // vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(2,vector<long>(3,0)));
    vector<vector<long>>curr(2,vector<long>(3,0));
    vector<vector<long>>next(2,vector<long>(3,0));
    for(int index= n-1;index>=0;index--){
        for(int buy = 1;buy>=0;buy--){
            for (int times =1;times>=0;times--){
                 if(index >=n || times >= 2){
                     curr[buy][times]=0;
                     continue;
                }
                if(buy){
                curr[buy][times]=max(-prices[index]+next[0][times],next[1][times]);
                 continue;
                }else{
                 curr[buy][times]= max(prices[index]+next[1][times+1],next[0][times]);
                 continue;
                }
            }
            next = curr;
        }
    }
    return (int)next[1][0];
    }
};