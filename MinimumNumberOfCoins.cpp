#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    int mincoins=0;
    for(int i=8;i>=0;i--){
    if(amount-arr[i]>=0){
       while(amount-arr[i]>=0){
        amount=amount-arr[i];
        mincoins++;
       }
     }
        if(amount==0) break;
    }
    return mincoins;
}

