#include <bits/stdc++.h>
using namespace std;
int utils(int i , int j, string &s, string &t, vector<vector<int>> &dp)
{
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	if(s[i] == t[j]) return dp[i][j] = 1 + utils(i - 1, j - 1, s, t, dp);

	return dp[i][j] = 0 + max(utils(i - 1, j, s, t, dp), utils(i, j - 1, s, t, dp));
}

int lcs(string s, string t) {
  // Write your code here
	if(s.size() == 0 || t.size() == 0) return 0;
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, - 1)) ;
	return utils(s.size() - 1, t.size() - 1, s, t, dp);
	
}
