#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N; // Number of coins
    if (!(cin >> N)) return;
    
    int Q; // Number of wishes
    cin >> Q;

    vector<int> coins(N + 1);
    vector<int> prefixXor(N + 1, 0);

    // Read coins and build Prefix XOR array
    for (int i = 1; i <= N; ++i) {
        cin >> coins[i];
        prefixXor[i] = prefixXor[i - 1] ^ coins[i];
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        // Apply the formula: P[R] ^ P[L-1]
        // This takes O(1) time per wish!
        int answer = prefixXor[R] ^ prefixXor[L - 1];
        
        cout << answer << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    solve();
    
    return 0;
}