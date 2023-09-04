#include<bits/stdc++.h>
class Solution {
public:

  bool f(int i,int n,int j,int m,string &pattern, string &text, vector<vector<int>> &dp){
   
    if (i == n && j == m) {
        dp[i][j] = true;
        return true;
    }

    if (dp[i][j] != -1) return  dp[i][j];
    bool result = false;

    if (i < n && j < m && (pattern[i] == text[j] || pattern[i] == '?')) {
        result = f(i + 1, n, j + 1, m, pattern, text, dp);
    } else if (i < n && pattern[i] == '*') {
        // Match zero or more characters with '*'
        result = f(i + 1, n, j, m, pattern, text, dp) || (j < m && f(i, n, j + 1, m, pattern, text, dp));
    }

    dp[i][j] = result ? 1 : 0;
    return result;

}
    bool isMatch(string s, string p) {
         int n = p.size();
         int m = s.size();
         // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         // return f(0,n,0,m,p,s,dp);
         vector<int>curr(m+1,0);
         vector<int>next(m+1,0);
         for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                 if (i == n && j == m) {
                     curr[j] = true;
                     continue;
                  }

                  bool result = false;

                  if (i < n && j < m && (p[i] == s[j] || p[i] == '?')) {
                     result = next[j+1];
                  } else if (i < n && p[i] == '*') {
                     // Match zero or more characters with '*'
                     result = next[j] || (j < m && curr[j+1]);
                  }

                  curr[j] = result ? 1 : 0;
                  
            }
            next = curr;
         }
         return next[0];
    }
};