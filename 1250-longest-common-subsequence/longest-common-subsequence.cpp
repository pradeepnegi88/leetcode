class Solution {
int f(int index1,int n,int index2,int m,string &first, string &second,vector<vector<int>> &dp){
	if(index1 == n || index2==m){
		return dp[index1][index2] = 0;
	}
	if(dp[index1][index2] !=-1) return dp[index1][index2];
	if(first[index1] == second[index2]){
		return dp[index1][index2] = 1+ f(index1+1,n,index2+1,m,first,second,dp);
	}else{
		return dp[index1][index2] = max(f(index1+1,n,index2,m,first,second,dp),f(index1,n,index2+1,m,first,second,dp));
	}
}

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
  int m = text2.size();
//   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//   return f(0,n,0,m,s,t,dp);
vector<int>curr(m+1,0);
vector<int>next(m+1,0);
for(int index1 = n;index1>=0;index1--){
	for(int index2 = m;index2>=0;index2--){
		if(index1 == n || index2==m){
			 curr[index2] = 0;
			 continue;
		}
		if(text1[index1] == text2[index2]){
			 curr[index2] = 1+ next[index2+1];
			 continue;
		}else{
			 curr[index2] = max(next[index2],curr[index2+1]);
			continue;
		}
	}
	next = curr;
}
return next[0];
    }
};