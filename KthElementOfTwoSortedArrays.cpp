int count(vector<int> &arr, int key)
{
    if(arr[0] > key)
        return 0;
    int l = 0, r = arr.size();
    while(r - l > 1)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] <= key)
            l = mid;
        else
            r = mid;
    }
    return l + 1;
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
    // Write your code here.
    int l = min(row1[0], row2[0]) - 1, r = max(row1.back(), row2.back());
    while(r - l > 1)
    {
        int mid = l + (r - l) / 2;
        int cnt = count(row1, mid) + count(row2, mid);
        if(cnt >= k)
            r = mid;
        else
            l = mid;
    }
    return r;
}
