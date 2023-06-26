#include <bits/stdc++.h> 

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for(int x : arr)
        mp[x]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(auto x : mp){
        minHeap.push({x.second, x.first});
        if (minHeap.size() > k)
            minHeap.pop();
    }
    vector<int> ans;
    while(!minHeap.empty())
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
