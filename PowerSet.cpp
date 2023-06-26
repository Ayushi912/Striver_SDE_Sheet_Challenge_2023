#include <bits/stdc++.h> 

void powerset(int i, vector<int> &num, vector<vector<int>> &ans, vector<int> &v)
{
    if(i == v.size())
    {
        ans.push_back(num);
        return;
    }
    powerset(i + 1, num, ans, v);
    num.push_back(v[i]);
    powerset(i + 1, num, ans, v);
    num.pop_back();
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<int> num;
    vector<vector<int>> ans;
    powerset(0, num, ans, v);
    return ans;
}
