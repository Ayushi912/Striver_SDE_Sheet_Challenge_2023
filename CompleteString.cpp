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

    /** Checks if all prefixes of any word present in trie.  */
    bool checkPrefix(string &word){
        Trie *cur = this;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return false;
            cur = cur -> child[ch - 'a'];
            if(cur -> isEnd == false)
                return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie *trie = new Trie();
    for(string &word : a)
        trie -> insert(word);
    string ans;
    for(string &word : a)
    {
        if(trie -> checkPrefix(word))
        {
            if(ans.size() == word.size())
                ans = min(ans, word);
            else if(ans.size() < word.size())
                ans = word;
        }
    }
    if(ans.empty())
        ans = "None";
    return ans;
}
