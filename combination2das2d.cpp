#include<bits/stdc++.h>
using namespace std;

int queenCombination(int n, int m, int r, int nRow, int mCol,  int rUsed, string &psf){
    
    if(nRow == n && mCol == 0){
        if(rUsed == r){
            cout<<psf<<endl;
            return 1;
        }
        return 0;
    }
    
    
    int nNewRow = nRow;
    int mNewCol = mCol + 1;
    string seperator;
    if(mCol == m - 1){
        nNewRow = nRow + 1;
        mNewCol = 0;
        seperator.push_back('\n');
    }
    
    psf.push_back('_');
    psf.push_back('_');
    psf.append(seperator);
    int notPick = queenCombination(n, m, r, nNewRow, mNewCol, rUsed, psf);
    psf.erase(psf.size() - seperator.size(),  seperator.size());
    psf.pop_back();
    psf.pop_back();
    
    
    psf.push_back('q');
    psf.push_back((char)('0' + rUsed));
    psf.append(seperator);
    int pick = queenCombination(n, m, r, nNewRow, mNewCol, rUsed + 1, psf);
    psf.erase(psf.size() - seperator.size(),  seperator.size());
    psf.pop_back();
    psf.pop_back();
    
    
    return notPick + pick;
}

int main() {
	int n,  m, r;
	// cin>>n>>m>>r;
    n =2;
    m=2;
    r=2;
	cout<<endl;
	string psf;
	cout<<queenCombination(n, m, r, 0, 0, 0, psf);
	cout<<endl;
	return 0;
}