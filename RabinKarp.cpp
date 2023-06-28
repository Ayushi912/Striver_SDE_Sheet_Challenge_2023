vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
        vector<int> positions;

    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            positions.push_back(i + 1);
        }
    }

    return positions;
}
