#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        bool flag = (a[0] <= k) || (n >= 2 && a[1] <= k) || (a[n-1] <= k) || (n >= 2 && a[n-2] <= k);
        if (flag) {
            int count = 0;
            for (int x : a) {
                if (x <= k) {
                    ++count;
                }
            }
            if (count >= 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
