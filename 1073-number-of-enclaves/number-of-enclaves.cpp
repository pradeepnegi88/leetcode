class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        vector<vector<int>> ans = grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            for (int i = 0; i < 4; ++i) {
                int rr = row + dx[i];
                int cc = col + dy[i];
                if (rr >= 0 && rr < n && cc >= 0 && cc < m && grid[rr][cc] == 1 && !visited[rr][cc]) {
                    visited[rr][cc] = 1;
                    q.push({rr, cc});
                     ans[rr][cc] = 0;

                }
            }
        }
    int count =0;
       for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
             if(ans[i][j]==1){
                 count = count+1;
             }

            }
       }
       return count;
        
    }
};