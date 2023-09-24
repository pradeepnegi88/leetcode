#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int permutation2d(int n,int m,int r,int ri,vector<vector<int> > &nmBoxes){
    
 if(ri == r){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nmBoxes[i][j] == -1){
                cout<< "--";
            }else{
                cout<<"q"<<nmBoxes[i][j];
            }
            if(j==m-1){
                cout<<endl;
            }
        }
    }
    cout<<endl;
    return 1;
 }
 
 int count = 0;
 for(int ni = 0;ni<n*m;ni++){
         int nRow = ni/m;
         int mCol = ni%m;
         if(nmBoxes[nRow][mCol] == -1){
             nmBoxes[nRow][mCol] = ri;
             count+=permutation2d(n,m,r,ri+1,nmBoxes);
             nmBoxes[nRow][mCol] = -1;
         }
 }
 return count;   
}


int main() {
    int n,  m, r;
    cin>>n>>m>>r;

    vector<vector<int> > nmBoxes(n,vector<int>(m,-1));
    cout<<endl;
    cout<<permutation2d(n,m,r,0,nmBoxes)<<endl;
    return 0;
}

