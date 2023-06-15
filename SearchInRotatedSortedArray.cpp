int search(int* a, int n, int target) {
    // Write your code here.
    int low = 0, high = n - 1; 
        while(low <= high) {
            int mid = (low + high) >> 1; 
            if(a[mid] == target) return mid; 
            
            // the left side is sorted
            if(a[low] <= a[mid]) {
                if(target >= a[low] && target <= a[mid]) {
                    high = mid - 1; 
                }
                else {
                    low = mid + 1; 
                }
            }
            else {
                if(target >= a[mid] && target <= a[high]) {
                    low = mid + 1; 
                }
                else {
                    high = mid - 1; 
                }
            }
        } 
        return -1; 
}
