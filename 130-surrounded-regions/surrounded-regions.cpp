class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        vector<vector<char>> ans(n,vector<char>(m,'X'));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O' && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    ans[i][j] = 'O';
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
                if (rr >= 0 && rr < n && cc >= 0 && cc < m && board[rr][cc] == 'O' && !visited[rr][cc]) {
                    visited[rr][cc] = 1;
                    q.push({rr, cc});
                     ans[rr][cc] = 'O';

                }
            }
        }

        board = ans;
    }
};
