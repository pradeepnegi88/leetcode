class Solution {
int f(int i,int n,int j,int m,string str1, string str2,vector<vector<int>> &dp)
{
   if(i == n){
       return dp[i][j] = m-j;
   }
   if(j == m){
       return dp[i][j] = n-i;
   }
   if(dp[i][j] != -1) return dp[i][j];
   if(str1[i] == str2[j]){
       return dp[i][j] = f(i+1,n,j+1,m,str1,str2,dp);
   }else{
       return dp[i][j] = 1+min(f(i+1,n,j,m,str1,str2,dp),
       min(f(i,n,j+1,m,str1,str2,dp),f(i+1,n,j+1,m,str1,str2,dp)));
   }
}    
public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
       int m = str2.size();
        //   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  vector<int>curr(m+1,0);
  vector<int>next(m+1,0);

//   return f(0,n,0,m,str1,str2,dp);
   for(int i = n;i>=0;i--){
       for (int j = m;j>=0;j--){
             if(i == n){
                 curr[j] = m-j;
                 continue;
            }
            if(j == m){
                 curr[j] = n-i;
                 continue;
            }
            if(str1[i] == str2[j]){
                 curr[j] = next[j+1];
                 continue;
            }else{
                 curr[j] = 1+min(next[j],min(curr[j+1],next[j+1]));
                 continue;
            }
       }
       next  = curr;
   }
   return next[0];
    }
};