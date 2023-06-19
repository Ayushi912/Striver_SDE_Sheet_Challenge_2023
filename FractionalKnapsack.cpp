#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        double ratioA = static_cast<double>(a.second) / a.first;
        double ratioB = static_cast<double>(b.second) / b.first;
        return ratioA > ratioB;
    });

    double maxValue = 0.0;

    for (const auto& item : items) {
        int weight = item.first;
        int value = item.second;

        if (w >= weight) {
            maxValue += value;
            w -= weight;
        } else {
            double fraction = static_cast<double>(w) / weight;
            maxValue += fraction * value;
            break;
        }
    }

    return maxValue;
}
