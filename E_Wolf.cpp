#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> p(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        while (q--) {
            int l, r, x;
            cin >> l >> r >> x;

            int idx = pos[x];

            if (idx < l || idx > r) {
                cout << -1 << ' ';
                continue;
            }

            int needLeft = 0, needRight = 0;
            int left = l, right = r;

            while (left <= right) {
                int m = (left + right) / 2;
                if (m == idx) break;

                if (m < idx) {
                    if (p[m] > x) needLeft++;
                    left = m + 1;
                } else {
                    if (p[m] < x) needRight++;
                    right = m - 1;
                }
            }

            // Count how many values < x and > x exist outside [l, r]
            int out_less = 0, out_greater = 0;
            for (int i = 1; i <= n; ++i) {
                if (i >= l && i <= r) continue;
                if (p[i] < x) out_less++;
                if (p[i] > x) out_greater++;
            }

            if (needLeft > out_less || needRight > out_greater) {
                cout << -1 << ' ';
            } else {
                cout << 2 * max(needLeft, needRight) << ' ';
            }
        }
        cout<<endl;
    }

    return 0;
}
