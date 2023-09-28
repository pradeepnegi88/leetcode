# include<bits/stdc++.h>
# include<iostream>
using namespace std;

int isValid(int r, int c, vector<vector<int> > &nBoxes) {
    int row = nBoxes.size();
    int col = nBoxes[0].size();

    // horizontal right 
    for (int i = c; i < col; i++) {
        if (nBoxes[r][i] != -1) {
            return false;
        }
    }

    // horizontal left 
    for (int i = c; i >= 0; i--) {
        if (nBoxes[r][i] != -1) {
            return false;
        }
    }

    // vertical top 
    for (int i = r; i >= 0; i--) {
        if (nBoxes[i][c] != -1) {
            return false;
        }
    }

    // vertical bottom 
    for (int i = r; i < row; i++) {
        if (nBoxes[i][c] != -1) {
            return false;
        }
    }

    // diagonal top-right 
    for (int i = r, j = c; i >= 0 && j < col; i--, j++) {
        if (nBoxes[i][j] != -1) {
            return false;
        }
    }

    // diagonal bottom-right 
    for (int i = r, j = c; i < row && j < col; i++, j++) {
        if (nBoxes[i][j] != -1) {
            return false;
        }
    }

    // diagonal top-left 
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (nBoxes[i][j] != -1) {
            return false;
        }
    }

    // diagonal bottom-left 
    for (int i = r, j = c; i < row && j >= 0; i++, j--) {
        if (nBoxes[i][j] != -1) {
            return false;
        }
    }

    return true;
}



int combination2d2(int n, int m, int r, int ri, vector<vector<int> > &nmBoxes, int lastRow) {
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
            if (nmBoxes[nr][nc] == -1 && isValid(nr,nc,nmBoxes)) {
                nmBoxes[nr][nc] = ri;
                count += combination2d2(n, m, r, ri + 1, nmBoxes, ni);
                nmBoxes[nr][nc] = -1;
            }
    
    }
    return count;
}

int main(){
    int n = 4;
    int m = 4;
    int r = 4;
    vector<vector<int> > nBoxes(n,vector<int>(m,-1));
    string psf;
    cout<< combination2d2( n, m, r, 0,nBoxes,-1)<<endl;
    return 0;
}