#include <iostream>
#include <vector>
using namespace std;

int combination2d2(int n, int m, int r, int ri, vector<vector<int>> &nmBoxes, int lastRow) {
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

    
    int count = 0;
    for (int ni = lastRow+1; ni < n*m; ni++) {
             int nr = ni/m;
             int nc = ni%m;
            if (nmBoxes[nr][nc] == -1) {
                nmBoxes[nr][nc] = ri;
                count += combination2d2(n, m, r, ri + 1, nmBoxes, ni);
                nmBoxes[nr][nc] = -1;
            }
    
    }
    return count;
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
   
    vector<vector<int>> nmBoxes(n, vector<int>(m, -1));
    cout << combination2d2(n, m, r, 0, nmBoxes, -1) << endl;
    return 0;
}
