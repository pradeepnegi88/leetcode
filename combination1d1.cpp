#include<bits/stdc++.h>
using namespace std;

int queenCombination(int n, int m, int r,int ni,  int rUsed, string &psf){
    
    if(ni == n*m){
        if(rUsed == r){
            cout<<psf<<endl;
            return 1;
        }
        return 0;
    }
    
    int currRow  = ni/m;
    int currColumn = ni%m;
    int nNewRow = currRow ;
    int mNewCol = currColumn + 1;
    string seperator;
    if(mNewCol == m - 1){
        seperator.push_back('\n');
    }
    
    psf.push_back('_');
    psf.push_back('_');
    psf.append(seperator);
    int notPick = queenCombination(n, m, r, ni+1, rUsed, psf);
    psf.erase(psf.size() - seperator.size(),  seperator.size());
    psf.pop_back();
    psf.pop_back();
    
    
    psf.push_back('q');
    psf.push_back((char)('0' + rUsed));
    psf.append(seperator);
    int pick = queenCombination(n, m, r, ni+1, rUsed + 1, psf);
    psf.erase(psf.size() - seperator.size(),  seperator.size());
    psf.pop_back();
    psf.pop_back();
    
    
    return notPick + pick;
}

int main() {
	int n,  m, r;
	cin>>n>>m>>r;
	cout<<endl;
	string psf;
	cout<<queenCombination(n, m, r, 0,0, psf);
	cout<<endl;
	return 0;
}