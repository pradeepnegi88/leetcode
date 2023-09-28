#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int permutationString(int n, int current, unordered_map<char, int> &m,vector<char> &spot,string &a) {
    if (current == n) {
       
       for(int i=0;i<n;i++){
     
            cout<<spot[i];
    
       }
       cout<<endl;
        return 1;
    }
    int lastOccurence = m[a[current]];
    int count = 0;
    for (int i = lastOccurence+1;i<n;i++) {
        if (spot[i]==NULL) { 
            spot[i]= a[current];
            m[a[current]] = i;
            count += permutationString(n, current + 1, m, spot,a);
            m[a[current]] = lastOccurence;
            spot[i]=NULL;
        }
    }
    return count;
}

int main() {
    string a = "aabb";
    unordered_map<char, int> mLastOccurence;
    for (auto c : a) {
     mLastOccurence[c]=-1;
    }
    vector<char> spot(a.size());
    cout << permutationString(a.size(), 0, mLastOccurence,spot,a) << endl;
    return 0;
}
