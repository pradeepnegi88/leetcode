class Solution {
public:

   bool dfs(int index, vector<int> adj[], vector<int> &visited,vector<int> &path){
            visited[index]=1;
            path[index]=1;
            for(auto it:adj[index]){
                if(visited[it] == 0){
                 if(dfs(it,adj,visited,path)){
                     return true;
                 }
                 }else if(visited[it] == 1 && path[it] == 1){
                     return true;
                 }
            }
            path[index]=0;
            return false;

            
   }
    bool isCyclic(int V, vector<int> adj[]) {
        stack<int> q;
        vector<int>visited(V,0);
        vector<int>path(V,0);

        for(int i=0;i<V;i++){
            if(visited[i] == 0){
                if(dfs( i,adj,visited,path)){
                    return true;
                }
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> adj[numCourses];  // Create adjacency list for numCourses

    for (auto a : prerequisites) {
        adj[a[0]].push_back(a[1]);  // Corrected order of prerequisites
    }

    return !isCyclic(numCourses, adj); 
    }
};