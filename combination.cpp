#include<bits/stdc++.h>
using namespace std;

int combination(int n,int r,int ni,int rUsed,string &psf){
    
    if(ni==n){
        if(r==rUsed){
            cout<<psf<<endl;
            return 1;
        }
        return 0;
    }
    //not picked 
    psf.push_back('_');
    int notPick = combination(n,r,ni+1,rUsed,psf);
    psf.pop_back();
    //pick
    psf.push_back((char)'0'+rUsed);
    int pick = combination(n,r,ni+1,rUsed+1,psf);
    psf.pop_back();
    
    return pick+notPick;
    
} 


int main() {
    int n,r;
	// cin>>n>>r;
    n = 4;
    r =2;

	string psf;
	cout<<combination(n,r,0,0,psf)<<endl;
	return 0;
}