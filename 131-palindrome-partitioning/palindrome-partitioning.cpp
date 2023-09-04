class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string> > answer;

        palindromePartition(0, s,ds,answer);
        return answer;
        
    }
    void palindromePartition(int index,string s,vector<string> &ds, vector<vector<string> > &answer){
        if(s.size() == index){
            answer.push_back(ds);
            return;
        }

        for(int i = index;i<s.size();i++){
            if(isPallindrome(s,index,i)){
             ds.push_back(s.substr(index,i-index+1));
             palindromePartition(i+1, s,ds,answer);
             ds.pop_back();
            }
        }
        return;
    }

    bool isPallindrome(string s,int index,int last){
        while(index<=last){
            if(s[index++]!= s[last--]){
                return false;
            }
        }
        return true;
    }
};