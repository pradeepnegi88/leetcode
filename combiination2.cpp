#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int combination2(int n,int r,int ri,vector<int>& nBoxes,int nLastUsed){
   
    if(ri == r){
        for(int i=0;i<n;i++){
            if(nBoxes[i] == -1){
                cout<<'_';
            }else{
                cout<<nBoxes[i];
            }
        }
        cout<<endl;
        return 1;
    }
   
   
    int count = 0;
    for(int ni = nLastUsed+1; ni<n; ni++){
        nBoxes[ni] = ri;
        count += combination2(n,r,ri+1,nBoxes,ni);
        nBoxes[ni] = -1;
    }
    
    return count;
    
}


int main() {
    int n,r;
    // cin>>n>>r;
      // cin>>n>>r;
    n = 4;
    r = 2;
    vector<int> nBoxes(n,-1);
    cout<<combination2(n,r,0,nBoxes,-1)<<endl;
	return 0;
}