#include <iostream>
#include <vector>
using namespace std;

int permutation2d2(int n, int m, int r, int ni, int rUsed, string &psf, vector<bool> &rItems) {
   
    if (ni/m == n) {
        if (rUsed == r) {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    
    int nRow = ni/m;
    int mCol = ni%m;

    int newRow = nRow;
    int newCol = mCol + 1;
    string separator;
    if (newCol == m) {
        newRow = nRow + 1;
        newCol = 0;
        separator.push_back('\n');
    }
    psf.push_back('_');
    psf.push_back('_');
    psf.append(separator);
    int notPick = permutation2d2(n, m, r,ni+1, rUsed, psf, rItems);
    psf.erase(psf.size() - separator.size(), psf.size());
    psf.pop_back();
    psf.pop_back();
    
    int pick = 0;
    for (int ri = 0; ri < r; ri++) {
        if (!rItems[ri]) {
            rItems[ri] = true;
            psf.push_back('q');
            psf.push_back((char)('0' + ri));
            psf.append(separator);
            pick += permutation2d2(n, m, r, ni+1, rUsed + 1, psf, rItems);
            psf.erase(psf.size() - separator.size(), psf.size());
            psf.pop_back();
            psf.pop_back();
            rItems[ri] = false;
        }
    }
    return pick + notPick;
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<bool> rItems(r, false);
    string psf;
    cout << endl;
    cout << permutation2d2(n, m, r, 0, 0, psf, rItems) << endl;
    return 0;
}
