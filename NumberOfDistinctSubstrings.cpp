#include <bits/stdc++.h>
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

    void erase(Trie *cur)
    {
        if(cur == nullptr)
            return;
        for (int i = 0; i < 26; i++) {
            erase(cur->child[i]);
            delete(cur -> child[i]);
            cur -> child[i] = nullptr;
        }
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.
    int ans = 0;
    Trie *trie = new Trie();
    for(int i = 0; i < word.size(); i++)
    {
        string sub;
        for(int j = i; j < word.size(); j++)
        {
            sub += word[j];
            if(!trie -> search(sub))
            {
                ans++;
                trie -> insert(sub);
            }
        }
    }
    trie -> erase(trie);
    delete(trie);
    return ans;
}
