#include <bits/stdc++.h> 
int kthLargest(vector<int>& nums, int size, int k)
{
	// Write your code here.
    sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}


