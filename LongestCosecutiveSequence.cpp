#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {

    if(arr.size() == 0)
    {
        return 0;
    }

    int len =1;
    int maxi = 1;

    sort(arr.begin(), arr.end());
    int prev = arr[0];
    for(int i = 1; i < n ; i++)
    {
        if(arr[i] == prev + 1)
        {
            len++;
            
        }
        else if(arr[i] != prev)
        {
            len = 1;
        }
        
        prev = arr[i];
        maxi = max(maxi, len);
        
    }

    return maxi;
}
