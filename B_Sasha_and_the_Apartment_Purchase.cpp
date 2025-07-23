#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin>>t;
    while(t--)
    {

        ll n = 6, k = 2;
        cin>>n>>k;
        vector<ll> bars(n);
        for(auto &it : bars) cin>>it;
        
        // Sort bar positions
        sort(bars.begin(), bars.end());
        
        // Set to store unique valid house numbers
        set<ll> valid_houses;
        
        // For each number of bars to close (i = 0 to k)
        for (ll i = 0; i <= k; ++i) {
            ll m = n - i; // Number of open bars
            if (m == 0) continue; // Need at least one bar
            
            // Compute prefix sums for the entire array
            vector<ll> prefix_sum(n + 1, 0);
            for (ll j = 0; j < n; ++j) {
                prefix_sum[j + 1] = prefix_sum[j] + bars[j];
            }
            
            // Slide window of size m
            ll min_f = LLONG_MAX; // Track minimal f(x) for this m
            set<ll> candidates; // Store medians with minimal f(x)
            
            for (ll l = 0; l <= n - m; ++l) {
                ll r = l + m - 1; // Right end of window
                ll median_idx = l + (m - 1) / 2; // Median index (0-based)
                ll median = bars[median_idx]; // Median position
                
                // Compute f(median) = sum |median - y| for y in window [l, r]
                ll left_count = (m + 1) / 2; // Bars <= median (including median)
                ll right_count = m - left_count; // Bars > median
                
                // Sum of distances:
                // Left: sum(median - y) for y <= median
                // Right: sum(y - median) for y > median
                ll sum_left = 0, sum_right = 0;
                if (left_count > 0) {
                    sum_left = median * left_count - (prefix_sum[median_idx + 1] - prefix_sum[l]);
                }
                if (right_count > 0) {
                    sum_right = (prefix_sum[r + 1] - prefix_sum[median_idx + 1]) - median * right_count;
                }
                ll f_median = sum_left + sum_right;
                
                // Update minimal f(x) and candidates
                if (f_median < min_f) {
                    min_f = f_median;
                    candidates.clear();
                    candidates.insert(median);
                } else if (f_median == min_f) {
                    candidates.insert(median);
                }
                
                // If even number of bars, check the next median and range
                if (m % 2 == 0 && median_idx + 1 <= r) {
                    ll next_median = bars[median_idx + 1];
                    // Compute f(next_median)
                    ll next_left_count = m / 2; // Bars <= next_median
                    ll next_right_count = m - next_left_count; // Bars > next_median
                    ll next_sum_left = next_median * next_left_count - (prefix_sum[median_idx + 1] - prefix_sum[l]);
                    ll next_sum_right = (prefix_sum[r + 1] - prefix_sum[median_idx + 2]) - next_median * (next_right_count - 1);
                    ll f_next_median = next_sum_left + next_sum_right + abs(next_median - median);
                    
                    if (f_next_median < min_f) {
                        min_f = f_next_median;
                        candidates.clear();
                        candidates.insert(next_median);
                        // Include range [median + 1, next_median]
                        for (ll x = median + 1; x <= next_median && x <= 109; ++x) {
                            candidates.insert(x);
                        }
                    } else if (f_next_median == min_f) {
                        candidates.insert(next_median);
                        for (ll x = median + 1; x <= next_median && x <= 109; ++x) {
                            candidates.insert(x);
                        }
                    }
                }
            }
            
            // Add all medians with minimal f(x) to valid_houses
            for (ll x : candidates) {
                if (x >= 1 && x <= 109) {
                    valid_houses.insert(x);
                }
            }
        }
        
        // Output the number of valid houses
        cout << valid_houses.size() << endl;
    }
    
    return 0;
}