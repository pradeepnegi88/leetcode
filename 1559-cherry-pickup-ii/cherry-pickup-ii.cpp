class Solution {
public:
    int f(int r,int c1,int c2,int n, int m, vector<vector<int>> &grid, 
    vector<vector<vector<int>>> &dp){
          if(c1<0 || c1>m-1 || c2<0 || c2>m-1){
              return -1e8;
          }
          if(r == n-1){
              if(c1 == c2){
                  return grid[r][c2];
              }else{
                  return grid[r][c1]+grid[r][c2];
              }
          }
          if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];  
          int maxi = -1e8;
          for (int i = -1; i<=1; i++){
              for (int j = -1; j<=1; j++){
                   int value = 0;
                   if(c1 == c2){
                   value = grid[r][c1];
                   }else{
                    value = grid[r][c1]+grid[r][c2];
                   }
                   value+=f(r+1,c1+i,c2+j,n,m,grid,dp);
                   maxi = max(maxi,value);
              }
          } 
        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return f(0,0,m-1,n,m,grid,dp);
    }
};