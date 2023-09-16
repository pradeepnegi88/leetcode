#include <iostream>
#include <vector>
using namespace std;

int combination2d2(int n, int m, int r, int ri, vector<vector<int>> &nmBoxes, int lastRow, int lastCol) {
    if (ri == r) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nmBoxes[i][j] == -1) {
                    cout << "--";
                } else {
                    cout << "q" << nmBoxes[i][j];
                }
                if (j == m - 1) {
                    cout << endl;
                }
            }
        }
        cout << endl;
        return 1;
    }

    int nextRow = lastRow;
    int nextCol = lastCol + 1;
    if (lastCol == m - 1) {
        nextRow = lastRow + 1;
        nextCol = 0;
    }
    
    int count = 0;
    for (int ni = nextRow; ni < n; ni++) {
        for (int rl = nextCol; rl < m; rl++) {
            if (ni >= 0 && ni < n && rl >= 0 && rl < m && nmBoxes[ni][rl] == -1) {
                nmBoxes[ni][rl] = ri;
                count += combination2d2(n, m, r, ri + 1, nmBoxes, ni, rl);
                nmBoxes[ni][rl] = -1;
            }
        }
        nextCol = 0;
    }
    return count;
}

int main() {
    int n, m, r;
    // cin >> n >> m >> r;
    n=2;
    m=2;
    r=2;
    vector<vector<int>> nmBoxes(n, vector<int>(m, -1));
    cout << combination2d2(n, m, r, 0, nmBoxes, -1, -1) << endl;
    return 0;
}
