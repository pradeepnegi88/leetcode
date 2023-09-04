class Solution {
public:

   int f(int r,int c,int n,int m,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(r<n && c<m && arr[r][c] == 1){
            // dp[r][c] = 0;
           return 0;
        }
       
       if(r == n-1 && c == m-1){
        //    dp[r][c] = 1;
           return 1;
       }
    
      if(r>n || c> m){
            // dp[r][c] =c0;
           return 0;
        }
       if(dp[r][c]!=-1) return dp[r][c];
       int right = 0;
       int down = 0;
       right = f(r,c+1,n,m,arr,dp);
       down =  f(r+1,c,n,m,arr,dp);
       return dp[r][c] = right+down;
   }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);

        for(int r = n-1;r>=0;r--){
            for(int c=m-1;c>=0;c--){
                      if(r<n && c<m && obstacleGrid[r][c] == 1){
                                curr[c] = 0;
                                continue;
                                }
                            
                            if(r == n-1 && c == m-1){
                                   curr[c] = 1;
                               continue;
                            }
                            
                            if(r>n || c> m){
                               curr[c] = 0;
                               continue;
                                }
                                  long long right = 0;
                                    long long down = 0;
                            right =curr[c+1];
                            down =  next[c];
                            curr[c] = right+down;
            }
            next = curr;
        }
        return curr[0];
    }
};