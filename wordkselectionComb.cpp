#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int combination(string unique,int k,int current,string &psf,int ni){
    if(ni == unique.size()){
        if(current == k){
            cout<<psf<<endl;
            return 1;
        }
        return 0;
    }


   psf.push_back(unique[current]);
   int pick = combination(unique,k,current+1,psf,ni+1);
   psf.pop_back();

   psf.push_back(' ');
   int notPick = combination(unique,k,current,psf,ni+1);
   psf.pop_back();

   return notPick+pick;
}


int combination2(string unique,int k,int current,vector<int> &board,int last){
        if(current == k){
            for(int i=0;i<unique.size();i++){
            if(board[i] == -1){
                cout<<'_';
            }else{
                cout<<unique[i];
            }
        }
        cout<<endl;
        return 1;
        }

    

 int count =0;
   for(int ni = last+1;ni<unique.size();ni++){
    if(board[ni]==-1){
         board[ni] = current;
         count+=combination2(unique,k,current+1,board,ni);
         board[ni] = -1;
    }
   }
   return count;
}



int main(){
    string a = "aabbbccdde";
    int k = 3;

    unordered_map<char,int> m;
    string unique;
    for(auto ch:a){
        if(m.count(ch) == 0){
            m[ch] = 1;
            unique.push_back(ch);
        }
    }
    cout<<unique<<endl;
    string psf;

    cout<<combination(unique,k,0,psf,0)<<endl;
   cout<<"###################################"<<endl;

    vector<int>board(unique.size(),-1);
    cout<<combination2(unique,k,0,board,-1)<<endl;

    return 0;
}