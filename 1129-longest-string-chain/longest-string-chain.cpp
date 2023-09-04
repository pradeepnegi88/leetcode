class Solution {

     
public:
            bool isMatched(string &larger,string &shorter){
            if(larger.size() == shorter.size()+1){
            int first=0;
            int second =0;
            while(first<larger.size()){
                if(larger[first] == shorter[second]){
                    first++;
                    second++;
                }else{
                    first++;
                }
            }
            return (larger.size() == first && shorter.size()== second);
            }else{
                return false;
            }
        }
        static bool cmp(string &a,string &b){
            return a.size()<b.size();
        }
    int longestStrChain(vector<string>& words) {
         int n = words.size();
        int maxi = 1;
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if(isMatched(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                }
            }
            if(maxi<dp[i]){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};