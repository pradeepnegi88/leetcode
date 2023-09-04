class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
         int n = text1.size();
        int m = text2.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,0));

		for(int index1 = n;index1>=0;index1--){
			for(int index2 = m;index2>=0;index2--){
				if(index1 == n || index2==m){
					dp[index1][index2] = 0;
					continue;
				}
				if(text1[index1] == text2[index2]){
					dp[index1][index2] = 1+ dp[index1+1][index2+1];
					continue;
				}else{
					dp[index1][index2] = max(dp[index1+1][index2],dp[index1][index2+1]);
					continue;
				}
			}
        }

            string ans;
            int i = 0;
            int j = 0;
            while(i<=n-1 && j<=m-1){
                if(text1[i] == text2[j]){
                    ans+=text1[i];
                    i++;
                    j++;
                }else if(dp[i+1][j]>dp[i][j+1]){
                    ans+=text1[i];
                    i++;
                }else{
                ans+=text2[j];
                j++;
                }
            }
            while(i<n){
                ans+=text1[i];
                i++;
                }
                while(j<m){
                    ans+=text2[j];
                    j++;
                    }
            return ans;

    }
};