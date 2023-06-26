#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	priority_queue<pair<int, pair<int, int>>> maxHeap;
	vector<int> ans;
	maxHeap.push({a[0] + b[0], {0, 0}});
        while(k--)
	{
		ans.push_back(maxHeap.top().first);
		int i = maxHeap.top().second.first, j = maxHeap.top().second.second;
		maxHeap.pop();
		if(i == 0 && j + 1 < n)
			maxHeap.push({a[i] + b[j + 1], {i, j + 1}});
		if(i + 1 < n)
			maxHeap.push({a[i + 1] + b[j], {i + 1, j}});
	}
	return ans;
}
