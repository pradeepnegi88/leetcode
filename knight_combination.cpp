# include<bits/stdc++.h>
# include<iostream>
using namespace std;

int isValid(int r, int c, vector<vector<int> > &nBoxes) {
    int row = nBoxes.size();
    int col = nBoxes[0].size();

  if(r-1>=0 && c-2>=0 && r-1<=col && c-2<=col && nBoxes[r-1][c-2]>0){
     return false;
  }

 if(r-2>=0 && c-1>=0 && r-2<=col && c-1<=col && nBoxes[r-2][c-1]>0){
     return false;
  }
if(r-1>=0 && c+2>=0 && r-1<=col && c+2<=col && nBoxes[r-1][c+2]>0){
     return false;
  }

 if(r-2>=0 && c+1>=0 && r-2<=col && c+1<=col && nBoxes[r-2][c+1]>0){
     return false;
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
                    cout << "k" << nmBoxes[i][j];
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