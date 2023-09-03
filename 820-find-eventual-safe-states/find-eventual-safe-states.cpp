class Solution {
public:
    bool dfs(int index,vector<vector<int>>& graph,vector<int> &visited,vector<int> &path,vector<int> &check){
      visited[index] = 1;
      path[index] = 1;
      check[index] = 0;
      for(auto it:graph[index]){
          if(visited[it]==0){
          if(dfs(it,graph,visited,path,check)){
              check[index] = 0;
            return true;
          }
          }else if(visited[it]==1 && path[it] ==1){
            check[index] = 0;
              return true;
          }
      }
      check[index] =1;
      path[index] = 0;
      return false;

    }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int size = graph.size();
    //     vector<int>visited(size,0);
    //     vector<int>safe;
    //     vector<int>path(size,0);
    //     vector<int>check(size,0);

    //     for(int i=0;i<size;i++){
    //         if(visited[i]==0){
    //             dfs(i,graph,visited,path,check);
    //         }
    //     }

    //       for(int i=0;i<size;i++){
    //         if(check[i]==1){
    //             safe.push_back(i);
    //         }
    //     }
    //     return safe;
    // }



    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //kahn's algo
        int size = graph.size();
        vector<int>safe;
        vector<int> adj[size];
        vector<int> indegree(size,0);
        queue<int> q;

      for(int i=0;i<size;i++){
          for(auto it:graph[i]){
              adj[it].push_back(i);
              indegree[i]++;
          }
      }
      
      for(int i=0;i<size;i++){
          if(indegree[i] == 0){
              q.push(i);
          }
      }
      while(!q.empty()){
        int curr = q.front();
        q.pop();
        safe.push_back(curr);
        for(auto it: adj[curr]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }

      }
       sort(safe.begin(),safe.end());
       return safe;
    }
};