#include<bits/stdc++.h>
using namespace std;

int permutation3(int n, int r, int ni, int rUsed, vector<int> &nBoxes){
    if(ni == n){
        if(rUsed == r){
            
            for(int i = 0;  i <n; i++){
                if(nBoxes[i] == -1) cout<<'_';
                else cout<<nBoxes[i];
            }
            cout<<endl;
            return 1;
        }
        return 0;
        
    }
    
    int notPick = permutation3(n, r, ni + 1, rUsed, nBoxes);
    
    
    int pick = 0;
    if(nBoxes[ni] == -1){
        nBoxes[ni] = rUsed;
        pick += permutation3(n, r, 0, rUsed + 1, nBoxes);
        nBoxes[ni] = -1;
    }
    
    return pick + notPick;
}

int main() {
	cout<<"GfG!";
	int n,  r;
	  // cin>>n>>r;
    n = 4;
    r = 2;
	vector<int> nBoxes(n, -1);
	cout<<endl<<permutation3(n, r, 0, 0, nBoxes);
	
	
	return 0;
}