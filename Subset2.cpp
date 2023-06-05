#include <bits/stdc++.h> 
void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);
        for(int i = ind;i<nums.size();i++) {
            if(i!=ind && nums[i] == nums[i-1]) continue; 
            ds.push_back(nums[i]); 
            findSubsets(i+1, nums, ds, ans); 
            ds.pop_back(); 
        }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
{
    // Write your code here.
    vector<vector<int>> ans; 
    vector<int> ds; 
    sort(nums.begin(), nums.end()); 
    findSubsets(0, nums, ds, ans);
    return ans; 
}
