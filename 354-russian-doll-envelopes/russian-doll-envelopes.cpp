class Solution {
public:
        static bool cmp(vector<int>& a, vector<int>& b)
        {
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),cmp);
        int n = envelopes.size();
        vector<int> temp;
        for(int i = 0;i<n;i++){
            if(temp.empty() || envelopes[i][1] > temp.back()){
                temp.push_back(envelopes[i][1]);
            }else{
                auto it = lower_bound(temp.begin(),temp.end(),envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return temp.size();
    }
};