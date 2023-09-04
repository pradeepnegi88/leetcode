class Solution {
public:

int f(int r1, int c1, int r2,int c2, int n, int m, vector<vector<int > > &grid, vector<vector<vector<vector<int>>>> &dp){

      if(r1>=n ||r2>=n||c1>=m || c2>=m|| grid[r1][c1] == -1||grid[r2][c2] == -1){
          return -1e9;
      }     
      if(r1 == n-1 && c1 == m-1){
            return grid[r1][c1];
      }
      if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        int count = 0;
        if(c1 == c2 && r1 == r2){
            count +=    grid[r1][c1];
          }else{
            count +=    grid[r1][c1]+grid[r2][c2];
          }
     int dd =  f(r1+1,c1,r2+1,c2,n,m,grid,dp);
     int dr =  f(r1+1,c1,r2,c2+1,n,m,grid,dp);
     int rr =  f(r1,c1+1,r2,c2+1,n,m,grid,dp);
     int rd =  f(r1,c1+1,r2+1,c2,n,m,grid,dp);
     count += max({rr,rd,dr,dd});
     return dp[r1][c1][r2][c2] = count;
   }
   


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(n+1,vector<int>(m+1,-1))));

        int ans = f(0,0,0,0,n,m,grid,dp);
        return (ans < 0) ? 0 : ans;
    }
};