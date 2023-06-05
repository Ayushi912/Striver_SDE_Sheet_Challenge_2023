#include <bits/stdc++.h> 
void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n){
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
}

vector<int> subsetSum(vector<int> &arr)
{
    // Write your code here.
    int N = arr.size();
    vector < int > ans;
    subsetSumsHelper(0, arr, N, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
