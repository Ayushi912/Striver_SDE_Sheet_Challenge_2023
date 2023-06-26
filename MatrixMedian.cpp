#include <bits/stdc++.h>
int getMedian(vector<vector<int>> &mat)
{
    // Write your code here.
    int mn = INT_MAX, mx = INT_MIN;
    int n = mat.size(), m = mat[0].size();
    for (int r = 0; r < n; r++) {
      mn = min(mn, mat[r][0]);
      mx = max(mx, mat[r][m - 1]);
    }
    int l = mn - 1, r = mx;
    while(r - l > 1)
    {
        int mid = l + (r - l) / 2;
        int count = 0;
        for(int r = 0; r < n; r++)
            count += upper_bound(mat[r].begin(), mat[r].end(), mid) - mat[r].begin();
        if(count * 2 >= m * n)
            r = mid;
        else
            l = mid;
    }
    return r;
}
