#include <bits/stdc++.h> 

class Trie {

    vector<Trie*> child;

public:

    /** Initialize your data structure here. */
    Trie() {
        child.resize(2);
    }

    /** Inserts a number into the trie. */
    void insert(int num) {
        Trie *cur = this;
        for(int bit = 30; bit >= 0; bit--)
        {
            int mask = 1 << bit;
            int isSet = (num & mask) > 0 ? 1 : 0;
            if(cur -> child[isSet] == nullptr)
                cur -> child[isSet] = new Trie();
            cur = cur -> child[isSet];
        }
    }

    /** Returns max xor in the trie. */
    int maxXor(int num) {
        Trie *cur = this;
        int ans = 0;
        for(int bit = 30; bit >= 0; bit--)
        {
            int mask = 1 << bit;
            int isSet = (num & mask) > 0 ? 1 : 0;
            if(cur -> child[!isSet] == nullptr)
                cur = cur -> child[isSet];
            else {
                cur = cur->child[!isSet];
                ans |= mask;
            }
        }
        return ans;
    }
};


int maximumXor(vector<int> A)
{
    // Write your code here. 
    Trie *trie = new Trie();
    int ans = 0;
    for(int x : A)
    {
        trie -> insert(x);
        ans = max(ans, trie -> maxXor(x));
    }
    return ans;
}
