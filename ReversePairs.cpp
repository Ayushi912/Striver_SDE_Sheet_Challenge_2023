#include <bits/stdc++.h> 

int binarySearch(vector<int>& sortedArr, int num) {

	int start = 0, end = sortedArr.size() - 1;
	
	while(start <= end) {

		int mid = (start + end)/2;

		if(sortedArr[mid] > num) {

			if(mid == 0) return sortedArr.size();

			else if(sortedArr[mid - 1] <= num) return sortedArr.size() - mid;

			else end = mid - 1;
		}

		else start = mid + 1;
	}

	return 0;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	int ans = 0;
	vector<int> sortedArr;
	sortedArr.push_back(arr[0]);

	for(int i = 1; i < arr.size(); i++) {

		ans+= binarySearch(sortedArr, 2*arr[i]);
		
		auto it = upper_bound(sortedArr.begin(), sortedArr.end(), arr[i]);
		sortedArr.insert(it, arr[i]);
	}

	return ans;
}
