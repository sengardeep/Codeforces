#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
typedef long long ll;
const int MAX_N = 10;
const int MAX_DIM = 150;
static vec<vec<vec<vec<int>>>> bottom_lists_table;
static int fib[MAX_N];

static bool can_pack(const vec<int>& bl, int W, int H) {
    int usedH = 0, rowW = 0, rowH = 0;
    for (int s : bl) {
        if (s > W || s > H) return false;
        if (rowW + s <= W) {
            rowW += s;
            rowH = max(rowH, s);
        } else {
            usedH += rowH;
            if (usedH + s > H) return false;
            rowW = s;
            rowH = s;
        }
    }
    usedH += rowH;
    return usedH <= H;
}

static void precompute_bottom_lists() {
    bottom_lists_table.assign(MAX_N + 1, vec<vec<vec<int>>>(MAX_DIM + 1));
    for (int n = 2; n <= MAX_N; ++n) {
        fib[0] = 1, fib[1] = 2;
        for (int i = 2; i < n; i++) fib[i] = fib[i-1] + fib[i-2];
        int full_mask = (1 << n) - 1, fmax = fib[n - 1];
        vec<int> sum_mask(1 << n);
        for (int mask = 1; mask <= full_mask; ++mask) {
            int lsb = mask & -mask;
            int idx = __builtin_ctz(lsb);
            sum_mask[mask] = sum_mask[mask ^ lsb] + fib[idx];
        }
        vec<int> dp(1 << n);
        for (int H = 1; H <= MAX_DIM; ++H) {
            if (H < fmax) continue;
            dp[0] = 0;
            for (int mask = 1; mask <= full_mask; ++mask) {
                if (sum_mask[mask] <= H) dp[mask] = 1;
                else {
                    int best = n + 1;
                    for (int s = (mask - 1) & mask; s; s = (s - 1) & mask) {
                        if (sum_mask[s] <= H)
                            best = min(best, dp[mask ^ s] + 1);
                    }
                    dp[mask] = best;
                }
            }
            int bins = dp[full_mask];
            if (bins > n) continue;
            vec<vec<int>> valid_subsets(1 << n);
            for (int mask = 1; mask <= full_mask; ++mask) {
                int lsb = mask & -mask, i = __builtin_ctz(lsb), rem = mask ^ (1 << i);
                for (int s = rem;; s = (s - 1) & rem) {
                    int full = s | (1 << i);
                    if (sum_mask[full] <= H) valid_subsets[mask].pb(full);
                    if (!s) break;
                }
            }
            set<vec<int>> bottom_sets;
            vec<int> stack;
            function<void(int, int)> dfs = [&](int rem, int bleft) {
                if (bleft == 1) {
                    if (sum_mask[rem] <= H) {
                        int idx = 31 - __builtin_clz(rem);
                        stack.pb(fib[idx]);
                        auto tmp = stack; sort(all(tmp), greater<>());
                        bottom_sets.insert(tmp);
                        stack.pop_back();
                    }
                    return;
                }
                for (int s : valid_subsets[rem]) {
                    int idx = 31 - __builtin_clz(s);
                    stack.pb(fib[idx]);
                    dfs(rem ^ s, bleft - 1);
                    stack.pop_back();
                }
            };
            dfs(full_mask, bins);
            bottom_lists_table[n][H] = vec<vec<int>>(all(bottom_sets));
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vec<array<int, 3>> a(m);
    for (int i = 0; i < m; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    vec<int> fibn(n); fibn[0] = 1; if (n >= 2) fibn[1] = 2;
    for (int i = 2; i < n; i++) fibn[i] = fibn[i-1] + fibn[i-2];
    int fmax = fibn[n-1];
    string ans; ans.reserve(m);
    for (int i = 0; i < m; i++) {
        int d[3] = {a[i][0], a[i][1], a[i][2]};
        bool ok = false;
        for (int j = 0; j < 3 && !ok; j++) {
            int H = d[j];
            if (H < fmax) continue;
            int w = d[(j+1)%3], l = d[(j+2)%3];
            auto &blist = bottom_lists_table[n][H];
            if (blist.empty()) continue;
            for (auto &bl : blist) {
                if (can_pack(bl, w, l) || can_pack(bl, l, w)) {
                    ok = true;
                    break;
                }
            }
        }
        ans.pb(ok ? '1' : '0');
    }
    cout << ans << endl;
}

signed main() {
    precompute_bottom_lists();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) solve();
}
