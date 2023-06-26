#include <bits/stdc++.h>
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {

    vector<Trie*> child;
    bool isEnd;

public:

    /** Initialize your data structure here. */
    Trie() {
        child.resize(26);
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur = this;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                cur -> child[ch - 'a'] = new Trie();
            cur = cur -> child[ch - 'a'];
        }
        cur -> isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur = this;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return false;
            cur = cur -> child[ch - 'a'];
        }
        return cur -> isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur = this;
        for(char ch : prefix)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return false;
            cur = cur -> child[ch - 'a'];
        }
        return true;
    }
};
