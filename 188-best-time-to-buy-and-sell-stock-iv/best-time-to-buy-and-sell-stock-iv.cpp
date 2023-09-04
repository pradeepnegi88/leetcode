class Solution {
public:
        int f(int index,int txn,int n,int k,vector<int> &prices,vector<vector<int>> &dp){

            if(index == n || txn == 2*k){
                return dp[index][txn] = 0;
            }
            if(dp[index][txn]!=-1)return dp[index][txn];
            if(txn %2 == 0){
            return dp[index][txn] = max(-prices[index]+f(index+1,txn+1,n,k,prices,dp),f(index+1,txn,n,k,prices,dp));
            }else{
            return dp[index][txn] = max(prices[index]+f(index+1,txn+1,n,k,prices,dp),f(index+1,txn,n,k,prices,dp));
            }
        }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

          //   vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));  
        //   return f(0,0,n,k,prices,dp);
        //   vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));  
        vector<int>curr(2*k+1,0);
        vector<int>next(2*k+1,0);

        for(int index = n;index>=0;index--){
            for(int txn = 2*k;txn>=0;txn--){
                if(index == n || txn == 2*k){
                        curr[txn] = 0;
                        continue;
                    }
                    if(txn %2 == 0){
                    curr[txn] = max(-prices[index]+next[txn+1],next[txn]);
                    continue;
                    }else{
                    curr[txn] = max(prices[index]+next[txn+1],next[txn]);
                    continue;
                    }
            }
            next  = curr;
        }
        return next[0];
    }
};