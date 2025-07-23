#include <bits/stdc++.h>
using namespace std;

#define int long long

int calculateLuckyValue(int n, int k) {
    int luckyValue = 0;
    deque<pair<int, int>> segments;  // Store the current segments to observe
    segments.push_back({1, n});

    while (!segments.empty()) {
        pair<int, int> segment = segments.front();
        segments.pop_front();
        int l = segment.first, r = segment.second;

        if (r - l + 1 < k) continue;  // Don't observe if the segment is too small

        // Middle of the current segment
        int m = (l + r) / 2;
        luckyValue += m;

        // If the segment is large enough, split it into two smaller segments
        if (m - 1 >= l) segments.push_back({l, m - 1});
        if (m + 1 <= r) segments.push_back({m + 1, r});
    }

    return luckyValue;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << calculateLuckyValue(n, k) << "\n";
    }

    return 0;
}
