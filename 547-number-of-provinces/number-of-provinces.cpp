class Solution {
public:
    void f(int index,vector<vector<int>>& isConnected,vector<int> &visited){
         visited[index] = 1;
             for(int j= 0;j<isConnected.size();j++){
                   if(isConnected[index][j] == 1 && !visited[j] && index!=j){
                       f(j,isConnected,visited);
                   }
             }
    }

   void iterativedfs(int index,vector<vector<int>>& isConnected,vector<int> &visited){
    stack<pair<int,int>>s;
    s.push({index,0});
    while(!s.empty()){
        auto &curr = s.top();
        auto currIndex = curr.first;
        auto &state = curr.second;
        if(state == 0){
         state++;
         if( !visited[currIndex]){
             visited[currIndex] = 1;
         }else{
             continue;
         }
           for(int j= 0;j<isConnected.size();j++){
                   if(isConnected[currIndex][j] == 1 && !visited[j] && currIndex!=j){
                       s.push({j,0});

                    }
             }
        }else{
            s.pop();
        }
    }

   }

    void iterativebfs(int index,vector<vector<int>>& isConnected,vector<int> &visited){
        queue<int>q;
        q.push(index);
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if( !visited[curr]){
             visited[curr] = 1;
         }else{
             continue;
         } 
           for(int j= 0;j<isConnected.size();j++){
                   if(isConnected[curr][j] == 1 && !visited[j] && curr!=j){
                      q.push(j);
                    }
             }
        }
    }

   
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int c =0 ;
        for(int i = 0;i<isConnected.size();i++){
           if(!visited[i]){
                c++;
            //    f(i,isConnected,visited);
            //    iterativedfs(i,isConnected,visited);
                              iterativebfs(i,isConnected,visited);

           }
        }
        return c;
    }
};