class Solution {
public:
    void bfs(int row,int col,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& visited){
      queue<pair<int,int>> q;
      cout<<row<<" row "<<col<<" col "<<endl;
      q.push({row,col});
      while(!q.empty()){
          auto curr = q.front();
          q.pop();
          int r = curr.first;
          int c = curr.second;
          if(visited[r][c]) continue;
          visited[r][c] = 1;
          int dx[]={0,0,-1,1};
          int dy[]={-1,1,0,0};
          for(int i =0;i<4;i++){
                   int rr = r+dx[i];
                   int cc = c+dy[i];
                  if(rr>=0 && rr<n && cc>=0 && cc<m && !visited[rr][cc] && grid[rr][cc] == '1'){
                     q.push({rr,cc});
                  }
          } 
      }
    }
   
// r c-1    0 -1
// r c+1.   0 +1
// r-1 c.   -1,0
// r+1 c    +1, 0

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                     count++;
                    bfs(i,j,n,m,grid,visited);
                }
            }
        }
        return count;
    }
};

