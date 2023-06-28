#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int low, int high, bool reverse = false) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if ((!reverse && arr[j] <= pivot) || (reverse && arr[j] >= pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(vector<int>& arr, int low, int high, int k) {
    if (k >= 1 && k <= high - low + 1) {
        int partitionIndex = partition(arr, low, high);
        int leftSize = partitionIndex - low + 1;

        if (leftSize == k) {
            return arr[partitionIndex];
        } else if (leftSize > k) {
            return kthSmallest(arr, low, partitionIndex - 1, k);
        } else {
            return kthSmallest(arr, partitionIndex + 1, high, k - leftSize);
        }
    }

    return -1; // Invalid case
}

vector<int> kthSmallLarge(vector<int>& arr, int n, int k) {
    vector<int> result;

    int kthSmallestElement = kthSmallest(arr, 0, n - 1, k);
    int kthLargestElement = kthSmallest(arr, 0, n - 1, n - k + 1);

    result.push_back(kthSmallestElement);
    result.push_back(kthLargestElement);

    return result;
}
