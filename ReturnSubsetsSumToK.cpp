void subset(int i, vector<int> &v, int &k, vector<int> &nums, vector<vector<int>> &ans)
{
    if(i == nums.size())
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum == k)
            ans.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    subset(i + 1, v, k, nums, ans);
    v.pop_back();
    subset(i + 1, v, k, nums, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> v;
    vector<vector<int>> ans;
    subset(0, v, k, arr, ans);
    return ans;
}
