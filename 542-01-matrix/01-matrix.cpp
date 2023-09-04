class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0;i<n;i++){
            for (int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                    visited[i][j] = 1;
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
         auto curr = q.front();
         int distance = curr.first;
         int row = curr.second.first;
         int col = curr.second.second;
         q.pop();
         int dx[]={0,0,1,-1};
         int dy[]={1,-1,0,0};
         for(int i =0;i<4;i++){
             int rr = row+dx[i];
             int cc = col+dy[i];
             if(rr>=0 && rr<n && cc>=0 && cc<m && mat[rr][cc] == 1 && !visited[rr][cc]){
                 visited[rr][cc] = 1;
                 ans[rr][cc] = distance+1;
                 q.push({distance+1,{rr,cc}});
             }
         }
        }
        return ans;

    }
};