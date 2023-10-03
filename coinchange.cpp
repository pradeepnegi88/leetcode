
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int combination1( vector<int> &coins,string &psf, int current,int ssf,int total,int n ){
    if(current == n){
        if(total == ssf){
            cout<<psf<<endl;
            return 1;
        }
        return 0;
    }
    int notPick = combination1(coins,psf,current+1,ssf+0,total,n);
    psf.push_back('0' + coins[current]); 
    psf.push_back(',');
    int pick = combination1(coins,psf,current+1,ssf+coins[current],total,n);
    psf.pop_back();
    psf.pop_back();

   return pick + notPick;
}

//repetition allowed
int combination2(vector<int> &coins,string &psf, int current,int ssf,int total,int n ){
    if(current == n){
        if(total == ssf){
            cout<<psf<<endl;
            return 1;
        }
        return 0;
    }
   int pick = 0;
   for(int i = total/coins[current];i>=1;i--){
    for(int j=0;j<i;j++){
        psf.push_back('0' + coins[current]); 
    }
     pick += combination2(coins,psf,current+1,ssf+coins[current]*i,total,n);
      for(int j=0;j<i;j++){
        psf.pop_back(); 
    }
   }
   int notPick = combination1(coins,psf,current+1,ssf+0,total,n);

   return pick+notPick;


}

int permutation1(vector<int> &coins,string &psf, int current,int ssf,int total,int n,vector<int> &used ){

        if(total == ssf){
            cout<<psf<<endl;
            return 1;
        }
    

    int count = 0;
    for(int i = 0;i<n;i++){
        if(used[i] == -1){
            used[i] = coins[i];
            psf.push_back('0' + coins[i]); 
            count+=permutation1(coins,psf,current+1,ssf+coins[i],total,n,used);
            psf.pop_back();
            used[i] = -1;
        }
    }
  return count;

}
//repeated
int permutation2(vector<int> &coins,string &psf,int ssf,int total,int n ){
        if(ssf>total) return 0;
        if(total == ssf){
            cout<<psf<<endl;
            return 1;
        }


    int count = 0;
    for(int i = 0;i<n;i++){
            psf.push_back('0' + coins[i]); 
            count+=permutation2(coins,psf,ssf+coins[i],total,n);
            psf.pop_back();
    }
  return count;

}

int main(){
    int n= 5;
    int coinSum = 12;
    vector<int>coins;
    coins.push_back(2);
    coins.push_back(3);
    coins.push_back(5);
    coins.push_back(6);
    coins.push_back(7);
    string psf;
    cout<<combination1(coins,psf,0,0,coinSum,n)<<endl;
    cout<<"##################################"<<endl;
    cout<<combination2(coins,psf,0,0,coinSum,n)<<endl;
    cout<<"##################################"<<endl;
    vector<int>used(n,-1);
    cout<<permutation1(coins,psf,0,0,coinSum,n,used)<<endl;

    cout<<"##################################"<<endl;
    cout<<permutation2(coins,psf,0,coinSum,n)<<endl;

    return 0;
}