#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    for(int i = 0; i < k; i++)
    {
        if(!kArrays[i].empty())
            minHeap.push({kArrays[i][0], {i, 0}});
    }
    vector<int> ans;
    while(!minHeap.empty())
    {
        int num = minHeap.top().first, i = minHeap.top().second.first, j = minHeap.top().second.second;
        minHeap.pop();
        ans.push_back(num);
        if(j + 1 < kArrays[i].size())
            minHeap.push({kArrays[i][j + 1], {i, j + 1}});
    }
    return ans;
}
