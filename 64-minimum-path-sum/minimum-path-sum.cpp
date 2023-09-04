class Solution {
public:
//    int f(int r,int c, int n, int m,vector<vector<int>> &grid,vector<vector<int>> &dp){
//      if(r == n-1 && c == m-1){
//          return grid[n-1][m-1];
//      }
//      if(r>n-1 || c>m-1){
//          return 1e9;
//      }
//      int right =0;
//      int down = 0;
//      int current  = 0;
//      if(dp[r][c]!=-1)return dp[r][c];
//      if(r<=n-1 || c<=m-1){
//           current = grid[r][c];
//      }

//     //  if(c+1<=n-1)
//      right = current+f(r,c+1,n,m,grid,dp);
//     //  if(r+1<=n-1)
//      down =  current+ f(r+1,c,n,m,grid,dp);
//      return dp[r][c] = min(right,down);
//    }



    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);

        for (int r = n;r>=0;r--){
            for (int c = m;c>=0;c--){
                 if(r == n-1 && c == m-1){
                    curr[c] =  grid[n-1][m-1];
                    continue;
                }
                if(r>n-1 || c>m-1){
                     curr[c] = 1e9;
                     continue;
                }
                int right =0;
                int down = 0;
                int current  = 0;
                if(r<=n-1 || c<=m-1){
                    current = grid[r][c];
                }

                //  if(c+1<=n-1)
                right = current+curr[c+1];
                //  if(r+1<=n-1)
                down =  current + next[c];
                curr[c] = min(right,down);
            }
            next  = curr;
        }
       return curr[0];
    }
};