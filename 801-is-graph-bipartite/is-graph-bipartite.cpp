class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size();
        vector<int> isColor(n,-1);
        for(int i=0;i<n;i++){
            if(isColor[i]==-1){
             q.push(i);
             isColor[i] = 0;
             while(!q.empty()){
              int curr = q.front();
              q.pop();
              for(auto it: graph[curr]){
                if(isColor[it]==-1){
                    isColor[it] = !isColor[curr];
                     q.push(it);
                }else if(isColor[it]==isColor[curr]){
                    return false;
                }
              }
             }
            }
        }
        return true;
    }
};