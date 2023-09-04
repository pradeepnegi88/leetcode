class Solution {
public:
//    int f(int r,int c,int n,int m,vector<vector<int>> &dp){
//        if(r == n-1 && c==m-1){
//            return 1;
//        }
//        if( r > n || c > m) return 0;
//        if(dp[r][c]!=-1)return dp[r][c];
//        int right = 0;
//        int down = 0;
//        right += f(r,c+1,n,m,dp);
//        down += f(r+1,c,n,m,dp);
//        return dp[r][c] = down+right;
//    }


    int uniquePaths(int n, int m) {
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> next(m+1,0);
        vector<int> cur(m+1,0);

        for(int r = n-1;r>=0;r--){
            for (int c = m-1;c>=0;c--){
                  if(r == n-1 && c==m-1){
                      cur[c] = 1;
                        continue;
                    }
                    if( r > n || c > m) {
                       cur[c] = 0;
                       continue;
                        }
                    int right = 0;
                    int down = 0;
                    right += cur[c+1];
                    down += next[c];
                    cur[c] = down+right;
            }
            next  = cur;
        }
        return cur[0];
    }
};