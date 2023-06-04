#include <bits/stdc++.h> 
long getTrappedWater(long *height, int n){
    // Write your code here.
        long left=0,right=n-1;
        long res=0;
        long maxleft=0,maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft)
                    maxleft=height[left];
                else
                    res+=maxleft-height[left];
                left++;
            }else{
                if(height[right]>=maxright)
                    maxright=height[right];
                else
                    res+=maxright-height[right];
                right--;
            }
        }
        return res;
}
