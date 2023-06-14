#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(), arr.end()); // Sort the array in ascending order
    vector<vector<int>> triplets; // Vector to store the triplets

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue; // Skip duplicate elements to avoid duplicate triplets
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == K) {
                triplets.push_back({ arr[i], arr[left], arr[right] });

                // Skip duplicate elements
                while (left < right && arr[left] == arr[left + 1]) {
                    left++;
                }
                while (left < right && arr[right] == arr[right - 1]) {
                    right--;
                }

                // Move to the next unique pair
                left++;
                right--;
            }
            else if (sum < K) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return triplets;
}



