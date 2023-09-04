class Solution {
public:
    int minInsertions(string s) {
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
        return n- next[0];

    }
};