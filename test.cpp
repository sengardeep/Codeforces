#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long N, S, M, L;
    
    while (cin >> N >> S >> M >> L) {
        // Initialize with an artificially high number
        long long min_cost = 9e18; 
        
        // Loop for Type A (cost S, power 6)
        for (long long i = 0; i <= 100; i++) {
            // Loop for Type B (cost M, power 8)
            for (long long j = 0; j <= 100; j++) {
                
                long long power_so_far = (i * 6) + (j * 8);
                long long remaining_power = max(0LL, N - power_so_far);
                
                // Fill the exact remainder with Type C (cost L, power 12)
                // We use integer math to simulate ceil(remaining_power / 12.0)
                long long k = (remaining_power + 11) / 12; 
                
                long long current_cost = (i * S) + (j * M) + (k * L);
                
                min_cost = min(min_cost, current_cost);
            }
        }
        
        cout << min_cost % 1000000007LL << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}