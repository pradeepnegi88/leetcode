#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int permutationString(int n, int current, unordered_map<char, int> &m, string &psf) {
    if (current == n) {
        cout << psf << endl;
        return 1;
    }
    int count = 0;
    for (auto &k : m) {
        if (k.second > 0) { // Check if the character can be used
            m[k.first]--;
            psf.push_back(k.first);
            count += permutationString(n, current + 1, m, psf);
            psf.pop_back();
            m[k.first]++;
        }
    }
    return count;
}

int main() {
    string a = "aabb";
    unordered_map<char, int> m;
    for (auto c : a) {
        if (m.count(c)) {
            m[c]++;
        } else {
            m[c] = 1;
        }
    }
    string psf;
    cout << permutationString(a.size(), 0, m, psf) << endl;
    return 0;
}
