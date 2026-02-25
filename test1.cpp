#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read from input.txt and write to output.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> s(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> t[i];

    // Array to count swaps
    vector<int> diff(n + 2, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        // Mark the start and end of the range
        diff[l]++;
        diff[r + 1]--;
    }

    int swaps = 0;
    for (int i = 1; i <= n; i++) {
        // Add up marks to get total swaps for this slot
        swaps += diff[i];
        
        // Odd swaps mean we take from Box T
        if (swaps % 2 != 0) {
            cout << t[i] << (i == n ? "" : " ");
        } else {
            // Even swaps mean we take from Box S
            cout << s[i] << (i == n ? "" : " ");
        }
    }
    cout << "\n";

    return 0;
}