#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());//sorting to make interval elements closer
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++)
    {
        //if it cannot be merged
        if(ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]); //interval is appended to ans.
        }

        else
        {
        
            ans.back()[1] = max(ans.back()[1] , intervals[i][1]);//checks 
        /* ans.back()[1] refers to the second element of the last sub-vector in the ans vector.

Let's break it down step by step:

ans is a vector of vectors (vector<vector<int>>), representing a 2D vector.
ans.back() returns a reference to the last element in the ans vector, which itself is a sub-vector.
ans.back()[1] accesses the second element (index 1) of that last sub-vector.
      */  }
    }

    return ans;
}
