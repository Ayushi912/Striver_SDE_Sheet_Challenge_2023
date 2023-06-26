#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] > b[1];
    });
    vector<bool> deadline(3001);
    int ans = 0;
    for(auto &x : jobs)
    {
        int pos = x[0];
        while(pos > 0 && deadline[pos]) pos--;
        if(pos > 0)
        {
            ans += x[1];
            deadline[pos] = true;
        }
    }
    return ans;
}
