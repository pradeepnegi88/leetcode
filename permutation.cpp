#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int permuation(int n,int r, int ri, vector<int> &nBoxs){
    if(ri == r){
        for(int i=0;i<n;i++){
            if(nBoxs[i]==-1){
                cout<<'_';
            }else{
                cout<<nBoxs[i];
            }
        }
        cout<<endl;
        return 1;
    }
    int count = 0;
    for(int ni = 0; ni< n; ni++){
        if(nBoxs[ni]==-1){
            nBoxs[ni] = ri;
            count += permuation(n,r,ri+1,nBoxs);
            nBoxs[ni] = -1;
        }
    }
    return count;
} 

int main() {
    int n,r;
    // cin>>n>>r;
    n = 4;
    r = 2;
    vector<int> nBoxs(n,-1);
    cout<<permuation(n,r,0,nBoxs)<<endl;
	return 0;
}