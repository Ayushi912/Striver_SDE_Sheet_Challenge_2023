#include <bits/stdc++.h> 
class Trie{
    vector<Trie*> child;
    int isEnd, preCount;
    public:

    Trie(){
        // Write your code here.
        child.resize(26);
        isEnd = 0;
        preCount = 0;
    }

    void insert(string &word){
        // Write your code here.
        Trie *cur = this;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                cur -> child[ch - 'a'] = new Trie();
            cur = cur -> child[ch - 'a'];
            cur -> preCount++;    
        }
        cur -> isEnd++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Trie *cur = this;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return 0;
            cur = cur -> child[ch - 'a']; 
        }
        return cur -> isEnd;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Trie *cur = this;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return 0;
            cur = cur -> child[ch - 'a']; 
        }
        return cur -> preCount;
    }

    void erase(string &word){
        // Write your code here.
        erase_helper(0, this, word);
    }

    bool erase_helper(int i, Trie *cur, string &word)
    {
        if (i == word.size()) {
            cur -> isEnd--;
            return true;
        }
        if(cur -> child[word[i] - 'a'] == nullptr)
            return false;
        bool wordExists = erase_helper(i + 1, cur -> child[word[i] - 'a'], word);
        if(wordExists)
        {
            Trie *chld = cur -> child[word[i] - 'a'];
            chld -> preCount--;
            if (chld->preCount == 0) {
                delete (chld);
                cur->child[word[i] - 'a'] = nullptr;
            }
        }
        return wordExists;
    }
};
