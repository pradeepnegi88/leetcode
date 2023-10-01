#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int permutation1(string unique,int k,int current,vector<int> &slot,int ssf){
   if(current == unique.size()){
        if(ssf == k){
            for(int i=0;i<slot.size();i++){
                if(slot[i] != -1){
                    cout<<unique[slot[i]];
                }
            }
            cout<<endl;
            return 1;
        }
        return 0;
   }
    int notPick = permutation1(unique,k,current+1,slot,ssf);

    int pick =0;
    for(int i = 0;i<k;i++){
        if(slot[i] ==-1){
            slot[i] = current;
            pick+=permutation1(unique,k,current+1,slot,ssf+1);
            slot[i] = -1;
        }
    }
    return pick+notPick;
}

int permutation2(string unique,int k,int current,unordered_map<char,int> &m,string &psf){
   if(current == k){
    cout<<psf<<endl;
    return 1;
   }
    int count = 0 ;

    for(int i=0;i<unique.size();i++){
        if(m.count(unique[i]) == 0){
            m[unique[i]] =1;
            psf.push_back(unique[i]);
            count+=permutation2(unique,k,current+1,m,psf);
            psf.pop_back();
            m.erase(unique[i]);
        }
    }
    return count;
}


int permutation3(string a,int k,int current,vector<int> &slot,int ssf,unordered_map<char,int> &m){

    if(current == a.size()){
        if(ssf == k){
            for(int i=0;i<k;i++){
                if(slot[i]!=-1){
                    cout<< a[slot[i]];
                }
            }
            cout<<endl;
            return 1;
        }

        return 0;
    }
    auto ch = a[current];
    int lo = m[ch];
    int pick = 0;
    int notPick = 0;
    for(int i=lo+1;i<slot.size();i++){
        if(slot[i] == -1){
            slot[i] = current;
            m[ch] = i;
            pick+= permutation3(a,k,current+1,slot,ssf+1,m);
            m[ch] = lo;
            slot[i] = -1;
        }
    }
    if(lo == -1){
     notPick = permutation3(a,k,current+1,slot,ssf,m);
    }
    return pick+notPick;

}

int permutation4(string unique,int k,int current,unordered_map<char,int> &m,string &psf){
   if(current == k){
    cout<<psf<<endl;
    return 1;
   }
    int count =0 ;
    for(int i=0;i<unique.size();i++){
        auto ch = unique[i];
        if(m[ch]>0){
            m[ch]--;
            psf.push_back(ch);
            count+=permutation4(unique,k,current+1,m,psf);
            psf.pop_back();
            m[ch]++;

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
        }else{
            m[ch]++;
        }
    }
    cout<<unique<<endl;
    string psf;
    vector<int> slot(k,-1);
    cout<<permutation1(unique,k,0,slot,0)<<endl;

    cout<<"####################################################"<<endl;
    unordered_map<char,int> ma;
    cout<<permutation2(unique,k,0,ma,psf)<<endl;



    cout<<"####################################################"<<endl;
    unordered_map<char,int> maa;
    vector<int> slott(k,-1);
     for(auto ch:a){
        maa[ch] = -1;
    }
    cout<<permutation3(a,k,0,slott,0,maa)<<endl;

    cout<<"####################################################"<<endl;
    string p;
    cout<<permutation4(unique,k,0,m,p)<<endl;


    return 0;
}