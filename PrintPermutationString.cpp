#include <bits/stdc++.h>
void permute(int i, string &s, vector<string> &ans)
{
    if(i == s.size())
        ans.push_back(s);
    for(int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        permute(i + 1, s, ans);
        swap(s[i], s[j]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    permute(0, s, ans);
    return ans;
}
