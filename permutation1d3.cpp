#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int permutation2D3(int n, int m, int r, int ni, int rUsed, vector<vector<int>> &nmBoxes) {
    int nRow = ni/m;
    int mCol = ni%m;
    if (nRow == n) {
        if (rUsed == r) {
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
        return 0;
    }
 

    int notPick = permutation2D3(n, m, r, ni+1, rUsed, nmBoxes);

    int pick = 0;
    if (nmBoxes[nRow][mCol] == -1) {
        nmBoxes[nRow][mCol] = rUsed;
        pick += permutation2D3(n, m, r, 0, rUsed + 1, nmBoxes);
        nmBoxes[nRow][mCol] = -1;
    }

    return pick + notPick;
}

int main() {
    cout << "GfG!" << endl;
    int n, m, r;
    cin >> n >> m >> r;
  
    vector<vector<int>> nmBoxes(n, vector<int>(m, -1));
    cout << permutation2D3(n, m, r, 0, 0, nmBoxes) << endl;
    return 0;
}
