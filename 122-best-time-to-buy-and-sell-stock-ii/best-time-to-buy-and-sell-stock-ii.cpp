 #include<bits/stdc++.h>

class Solution {
public:

long f(int index,int buy,vector<int>& prices, int n,vector<vector<int>> &dp){

    if(index == n){
        return dp[index][buy]=0;
    }
    if(dp[index][buy]!=-1)return dp[index][buy];
    if(buy){
      return dp[index][buy]=max(-prices[index]+f(index+1,0,prices,n,dp),f(index+1,1,prices,n,dp));
    }else{
      return dp[index][buy] = max(prices[index]+f(index+1,1,prices,n,dp),f(index+1,0,prices,n,dp));
    }
}

    int maxProfit(vector<int>& prices) {
          int n =prices.size();
        //   vector<vector<int>> dp(n+1,vector<int>(2,-1)); 
        //    return f(0,1,prices,n,dp);
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for (int index = n;index>=0;index--){
            for (int buy = 1;buy>=0;buy--){
                if(index == n){
                        curr[buy]=0;
                        continue;
                    }
                    if(buy){
                    curr[buy]=max(-prices[index]+next[0],next[1]);
                    continue;
                    }else{
                    curr[buy] = max(prices[index]+next[1],next[0]);
                    continue;
                    }  
            }
            next = curr;
        }
        return next[1];   
    }
};