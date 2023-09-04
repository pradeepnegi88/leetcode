class Solution {
public:
    int f(int index,int sum,int n,int amount,vector<int>& coins,vector<vector<int>> &dp){
     if(index == n){
         return dp[index][sum] = (sum == amount);
     }
     if( dp[index][sum] != -1) return  dp[index][sum];
     int pick = 0 ;
     if(sum+coins[index]<=amount){
         pick+=f(index,sum+coins[index],n,amount,coins,dp);
     }
     int notPick = f(index+1,sum,n,amount,coins,dp);
     return dp[index][sum] = pick+notPick;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>curr(amount+1,-1);
        vector<int>next(amount+1,-1);
        // return f(0,0,n,amount,coins,dp);
        for(int index = n;index>=0;index--){
            for (int sum =amount;sum>=0;sum-- ){
                     if(index == n){
                         curr[sum] = (sum == amount);
                         continue;
                    }
                    int pick = 0 ;
                    if(sum+coins[index]<=amount){
                        pick+=curr[sum+coins[index]];
                    }
                    int notPick = next[sum];
                    curr[sum] = pick+notPick;
            }
            next  = curr;
        }
        return next[0];
    }
};