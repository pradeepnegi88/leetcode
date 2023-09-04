class Solution {
public:

    int f(int r, int c, int n, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(r == n-1){
            return grid[r][c];
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int diag = grid[r][c]+f(r+1,c+1,n,grid,dp);
        int down = grid[r][c]+f(r+1,c,n,grid,dp);
        return dp[r][c] = min(diag,down);      

    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size() ;
       vector<int>curr(n+1,0);
       vector<int>next(n+1,0);
       for (int r = n-1;r>=0;r--){
           for (int c = r;c>=0;c--){
                    if(r == n-1){
                        curr[c] = triangle[r][c];
                        continue; 
                    }
                    int diag = triangle[r][c]+next[c+1];
                    int down = triangle[r][c]+next[c];
                    curr[c] = min(diag,down);  
           }
           next = curr;
       }

       return curr[0]; 
    }
};