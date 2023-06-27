#include <bits/stdc++.h> 
bool areAnagram(string &s, string &t){
    // Write your code here.
    if (s.size()!=t.size()) return false;
        unordered_map <char, int> umap;
        for (int i=0; i<s.size(); i++) {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto it: umap) {
            if (it.second) return false;
        }
        return true;
}

