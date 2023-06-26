#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    for(int i = 0; i + 3 < n; i++)
    {
        for(int j = i + 1; j + 2 < n; j++)
        {
            int  k = j + 1, l = n - 1;
            while(k < l)
            {
                int sum = arr[i] + arr[j] +  arr[k] + arr[l];
                if(sum == target)
                    return "Yes";
                else if(sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return "No";
}
