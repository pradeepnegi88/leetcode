class Solution {

int f(int index1,int n,int index2,int m,string s,string t,vector<vector<int>> &dp){
    if(index1 == n || index2 == m){
        return dp[index1][index2] = 0;
    }
    if(dp[index1][index2]!=-1)return dp[index1][index2];
    if(s[index1] == t[index2]){
        return dp[index1][index2] = 1+f(index1+1,n,index2+1,m,s,t,dp);
    }else{
        return dp[index1][index2] = max(f(index1+1,n,index2,m,s,t,dp),f(index1,n,index2+1,m,s,t,dp));
    }
}    
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int m = n;
        string t = s;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        reverse(t.begin(),t.end());
        // return f(0,n,0,m,s,t,dp);
       vector<int>curr(n+1,0);
       vector<int>next(n+1,0);
        for(int index1 = n;index1>=0;index1--){
            for(int index2 = n;index2>=0;index2--){
                  if(index1 == n || index2 == m){
                         curr[index2] = 0;
                         continue;
                    }
                    if(s[index1] == t[index2]){
                        curr[index2] = 1+next[index2+1];
                         continue;
                    }else{
                        curr[index2] = max(next[index2],curr[index2+1]);
                         continue;
                    }
            }
            next  = curr;
        }
            return next[0];

    }
};