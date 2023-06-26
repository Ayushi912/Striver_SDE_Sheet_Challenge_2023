int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            k--;
        if(k < 0)
        {
            if(arr[j] == 0)
                k++;
            j++;
        }
    }
    return i - j;
}
