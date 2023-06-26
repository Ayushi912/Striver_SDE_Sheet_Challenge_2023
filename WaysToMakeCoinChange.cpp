#include<bits/stdc++.h>
using namespace std;
long helper(int* denominations,int n,int pos,int value,vector<vector<long>> &dp){
    if(value==0)return 1;
    if(pos==n)return 0;
    if(dp[pos][value]!=-1)return dp[pos][value];
    long a=0;
    if(value-denominations[pos]>=0){
        a=helper(denominations,n,pos,value-denominations[pos],dp);
    }
    long b=helper(denominations,n,pos+1,value,dp);
    return dp[pos][value]=a+b;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return helper(denominations,n,0,value,dp);
}
