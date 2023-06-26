#include <bits/stdc++.h> 
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(), positions.end());
	int l = 1, r = positions.back() - positions.front() + 1;
	while(r - l > 1)
	{
		int mid = l + (r - l) / 2;
		int count = 1, prev = positions[0];
		for(int i = 1; i < n; i++)
		{
			if(positions[i] - prev >= mid)
			{
				count++;
				prev = positions[i];
			}
		}
		if(count >= c)
			l = mid;
		else
			r = mid;
	}
	return l;
}
