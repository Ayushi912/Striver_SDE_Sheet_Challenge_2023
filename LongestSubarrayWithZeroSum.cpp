#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  int ans = 0;
  for(int i = 0; i< arr.size(); i++)
  {
    int sum = 0;

    for(int j = i ; j< arr.size(); j++)
    {
      sum += arr[j];

      if(sum == 0)
      {
        ans = max(ans, j-i+1);
      }
    }
  }

  return ans;

}
