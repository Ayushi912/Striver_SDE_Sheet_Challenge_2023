#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int m, int n, vector<int> time) 
{	
	// Write your code here.
	long long l = *max_element(time.begin(), time.end()) - 1, r = accumulate(time.begin(), time.end(), 0ll);
	while(r - l > 1)
	{
		long long mid = l + (r - l) / 2;
		long long count = 1, sum = 0;
		for(int x : time)
		{
			if(sum + x <= mid)
				sum += x;
			else
				count++, sum = x;
		}
		if(count <= m)
			r = mid;
		else
			l = mid;
	}
	return r;
}
