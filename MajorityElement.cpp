#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = arr[i];
        } else if (el == arr[i]) {
          cnt++;
        } else {
          cnt--;
        }
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}
