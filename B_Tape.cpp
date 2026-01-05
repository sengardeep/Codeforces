#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod=1e9+7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> seg(n);
    for (int i = 0; i < n; i++) cin >> seg[i];

    vector<int> gaps;
    for (int i = 1; i < n; i++) {
        gaps.push_back(seg[i] - seg[i-1] - 1);
    }

    sort(gaps.rbegin(), gaps.rend());

    int total = seg[n-1] - seg[0] + 1;

    for (int i = 0; i < min(k-1, (int)gaps.size()); i++) {
        total -= gaps[i];
    }

    cout << total << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}