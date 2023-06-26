#include <bits/stdc++.h> 

void solve(int i, string &st, vector<string> &ans, string &s, unordered_set<string> &dict)
{
    if(i == s.size())
    {
        st.pop_back();
        ans.push_back(st);
        st += " ";
        return;
    }

    string word;
    for(int j = i; j < s.size(); j++)
    {
        word += s[j];
        if(dict.find(word) != dict.end())
        {
            st += word + " ";
            solve(j + 1, st, ans, s, dict);
            st.pop_back();
            while(!st.empty() && st.back() != ' ')
                st.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    string st;
    solve(0, st, ans, s, dict);
    return ans;
}
