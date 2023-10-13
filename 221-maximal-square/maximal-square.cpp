class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;  // Handle empty matrix
        int col = matrix[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        int maxValue = 0;

        for (int r = row - 1; r >= 0; r--) {
            for (int c = col - 1; c >= 0; c--) {
                if (r == row - 1 || c == col - 1) {
                    ans[r][c] = matrix[r][c] - '0';
                } else {
                    if (matrix[r][c] == '0') {
                        ans[r][c] = 0;
                    } else {
                        int right = ans[r][c + 1];
                        int down = ans[r + 1][c];
                        int diagonal = ans[r + 1][c + 1];
                        ans[r][c] = min(min(right, down), diagonal) + 1;
                    }
                }
                if (ans[r][c] > maxValue) {
                    maxValue = ans[r][c];
                }
            }
        }
        return maxValue * maxValue;
    }
};
