class Solution {
 int f(int index,int n,vector<int> &num,int x,vector<vector<int>> &dp){
     if(index == n){
         if(x == 0){
           dp[index][x] = 0;
          return 0;
         }
          return dp[index][x] = 1e5;
         
     }
     if(dp[index][x]!=-1) return dp[index][x];
     int pick = 1e5;
     int notPick = 1e5;
     if(x-num[index]>=0){ 
       pick = 1+f(index,n,num,x-num[index],dp);

     }
      notPick = 0+f(index+1,n,num,x,dp);
     return dp[index][x] = min(pick,notPick);
}   
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
            vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

 int val = f(0,n,coins,amount,dp);
     if(val == 1e5){
      return  -1;
    }else{
       return val;
    };    }
};