#include<bits/stdc++.h>
int dp[10005][105];
int Solve(int n,int e)
{
   if(e==1)
     return n;
    if(n==1 or n==0)
         return n;
    if(dp[n][e]!=-1)
     return dp[n][e];
    int ans=INT_MAX;
    int low=1,high=n;
   while(low<=high)
   {
        int mid=(low+high)/2;
        int left=Solve(mid-1,e-1);
        int right=Solve(n-mid,e);
        int temp=1+max(left,right);
         if(left>right)
            high=mid-1; 
       else 
            low=mid+1;
        ans=min(ans,temp);
    }
    return dp[n][e]=ans;
}
int cutLogs(int k, int n)
{
   memset(dp,-1,sizeof(dp));
   return Solve(n,k);
}
