#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i = 0; i < n; i++)
	{
		int x = arr[i];
		minHeap.push(x);
		maxHeap.push(x);
		if(minHeap.size() > k)
			minHeap.pop();
		if(maxHeap.size() > k)
			maxHeap.pop();
	}
	return {maxHeap.top(), minHeap.top()};
}
