class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // queue<pair<vector<string>, int>> q;
        // unordered_set<string> s(wordList.begin(), wordList.end());
        // vector<vector<string>> ans;
        
        // if (!s.count(endWord)) {
        //     return ans;
        // }
        
        // q.push({vector<string>{beginWord}, 1});
        // int previousLevel = 0;
        
        // while (!q.empty()) {
        //     auto curr = q.front();
        //     auto ladder = curr.first;
        //     int count = curr.second;
            
        //     if (count > previousLevel) {
        //         for (const string& word : ladder) {
        //             s.erase(word);
        //         }
        //         previousLevel = previousLevel+1;
        //     }
            
        //     q.pop();

        //     if (ladder.back() == endWord) {
        //         if(ans.size() == 0){
        //         ans.push_back(ladder);
        //         }else if(ans[0].size() == ladder.size() ){
        //         ans.push_back(ladder);
        //         }else{
        //             return ans;
        //         }
                
        //     } 
        //         string word = ladder.back();
        //         for (int i = 0; i < word.size(); ++i) {
        //             char original = word[i];
        //             for (char j = 'a'; j <= 'z'; ++j) {
        //                 word[i] = j;
        //                 if (s.count(word)) {
        //                     vector<string> newLadder = ladder;
        //                     newLadder.push_back(word);
        //                     q.push({newLadder, count + 1});
        //                 }
        //             }
        //             word[i] = original;
        //         }
            
        // }
        
        // return ans;


        vector<vector<string>> ans;
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        map<string,vector<string>> adj;
        unordered_map<string,int>visited;
         if (!s.count(endWord)) {
            return ans;
        }
        q.push({beginWord,1});
        visited[beginWord] = 1;
        while(!q.empty()){
           auto curr = q.front();
           string word = curr.first;
           int count = curr.second;
           q.pop();
           for (int i=0;i<word.size();i++){
               char original = word[i];
               for(char j = 'a';j<='z';j++){
                   word[i] = j;
                   if(s.count(word) && visited.count(word) == 0 ){
                       adj[word].push_back(curr.first);
                       visited[word] = count+1;
                       q.push({word,count+1});
                   }else if( visited[word] == 1+visited[curr.first]){
                        adj[word].push_back(curr.first);
                   }
               }
               word[i] = original;
           }
        }
        // for(auto it: adj){
        //     cout<<it.first<<" --> ";
        //     for(auto i:it.second){
        //         cout<<i<<" , ";
        //     }
        //     cout<<endl;
        // }
        vector<string> v;
        dfs(endWord,v,adj,ans,beginWord);
    return ans;

    }

void dfs(string index, vector<string>& v, map<string, vector<string>>& adj, vector<vector<string>>& ans,string beg) {
    v.push_back(index);
    if (index == beg) {
        reverse(v.begin(), v.end());
        ans.push_back(v);
        reverse(v.begin(), v.end()); // Restore the vector for backtracking
    } else {
        for (auto it : adj[index]) {
            dfs(it, v, adj, ans,beg);
        }
    }
    v.pop_back(); // Backtrack by removing the current word from the vector
}
};


