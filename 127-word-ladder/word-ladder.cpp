class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
           auto curr = q.front();
           string word = curr.first;
           int count = curr.second;
           q.pop();
           if(word == endWord) return count;
           for (int i=0;i<word.size();i++){
               char original = word[i];
               for(char j = 'a';j<='z';j++){
                   word[i] = j;
                   if(s.count(word)){
                       q.push({word,count+1});
                       s.erase(word);
                   }
               }
               word[i] = original;
           }
        }
        return 0;
        
    }
};