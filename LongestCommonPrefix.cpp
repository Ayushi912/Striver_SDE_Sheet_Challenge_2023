string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
     if (n == 0) {
        return "";
    }

    string prefix = arr[0];
    for (int i = 1; i < n; i++) {
        while (arr[i].find(prefix) != 0) {
            prefix.pop_back();
            if (prefix.empty()) {
                return "";
            }
        }
    }

    return prefix;
}

