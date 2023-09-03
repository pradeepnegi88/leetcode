class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];  
    vector<int> indegree(numCourses,0);
    vector<int> ans;

    for (auto a : prerequisites) {
        adj[a[1]].push_back(a[0]); 
        indegree[a[0]]++;
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++){
      if(indegree[i] == 0){
          q.push(i);
      }
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto it:adj[curr]){
          indegree[it]--;
          if(indegree[it] ==0) {
              q.push(it);
          }
        }
    }
     if(ans.size()!=numCourses){
        vector<int> a;
        return a;
    }else{
return ans;
    }
    }
};