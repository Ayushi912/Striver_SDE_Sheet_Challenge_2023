#include <bits/stdc++.h> 
bool subset(vector<int>&arr,int i,int k,vector<vector<int>>&dp)
{
    if(k==0){
        return true;
    }
    if(i==0){
        return arr[0]==k;
            }
            if(dp[i][k]!=-1){
                return dp[i][k];
            }
            bool nt=subset(arr,i-1,k,dp);
            bool t=false;
            if(arr[i]<=k){
                t=subset(arr,i-1,k-arr[i],dp);
            }
            return dp[i][k]= nt||t;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int i=n-1;
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return subset(arr,i,k,dp);
}
