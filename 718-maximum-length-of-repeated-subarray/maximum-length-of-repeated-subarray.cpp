class Solution {
public:
    int findLength(vector<int>& s, vector<int>& t) {
          int n = s.size();
            int m = t.size();
            vector<int>curr(m+1,0);
                vector<int>next(m+1,0);
                int ans = 0;
                for(int index1 = n;index1>=0;index1--){
                    for(int index2 = m;index2>=0;index2--){
                        if(index1 == n || index2==m){
                            curr[index2] = 0;
                            continue;
                        }
                        if(s[index1] == t[index2]){
                            curr[index2] = 1+ next[index2+1];
                            ans = max(ans,curr[index2]);
                            continue;
                        }else{
                            curr[index2] = 0;
                            continue;
                        }
                    }
                    next = curr;
            }
        return ans;
    }
};