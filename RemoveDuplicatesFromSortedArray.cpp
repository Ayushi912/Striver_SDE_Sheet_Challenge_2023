int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	 if (n == 0 || n == 1) {
        return n; // No duplicates to remove
    }

    int j = 0; // Index for the unique elements

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i]; // Store the unique element
        }
    }

    arr[j++] = arr[n - 1]; // Store the last element (which is unique)

    return j; // Return the new length of the array
}


