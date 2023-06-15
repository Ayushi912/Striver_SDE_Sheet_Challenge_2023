#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int>freq;
    int i;
    vector<int>ans;

    for( i=0;i<arr.size();i++)
    {
          freq[arr[i]]++;
         
    }
    
    int k=floor(arr.size()/3);

    for(auto x:freq)
    {
        if(x.second>k)
        ans.push_back(x.first);
    }
    return ans;

}
