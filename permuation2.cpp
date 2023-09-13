#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int permutation2(int n,int r,int ni,int rused,string &psf,vector<bool> &rItems){
    if(ni == n){
        if(rused == r){
            cout<<psf<<endl;
            return 1;
        }
        return 0;
    }
    
    
    
    //not pick
    psf.push_back('_');
    int notPick = permutation2(n,r,ni+1,rused,psf,rItems);
    psf.pop_back();
    
    
    //pick
    int pick = 0;
    for(int ri = 0; ri< r; ri++){
        if(!rItems[ri]){
            rItems[ri] = true;
            psf.push_back((char)'0'+ri);
            pick += permutation2(n,r,ni+1,rused+1,psf,rItems);
            psf.pop_back();
            rItems[ri] = false;
        }
    }
    
    return pick+notPick;
    
    
}

int main() {
   int n,r;
	  // cin>>n>>r;
    n = 4;
    r = 2;
	string psf;
	vector<bool>rItems(n,false);
	cout<<permutation2(n,r,0,0,psf,rItems)<<endl;
	return 0;
}
