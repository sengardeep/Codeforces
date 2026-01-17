#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
    int n;
    cin >> n;
    auto ask = [&](int l, int r) {
        cout << "? " << l << " " << r << endl;
        int ans; cin >> ans;
        return ans;
    };

    int first_nonzero_idx = -1;
    int zeros_count = 0;

    // Step 1: Find the first "01" pattern
    // We check f(1, 2), f(1, 3)... until we get a value > 0
    for (int i = 2; i <= n; i++) {
        int curr = ask(1, i);
        if (curr > 0) {
            first_nonzero_idx = i;
            zeros_count = curr;
            break;
        }
    }

    // Step 2: Handle Impossible case
    // If we never found a "01", we can't tell strings like "100" from "000"
    if (first_nonzero_idx == -1) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    // Step 3: Reconstruct the start of the string
    // We know we have 'zeros_count' zeros.
    // Since f(1, i-1) was 0, all 1s must be before all 0s in the prefix.
    string s = "";
    int ones_count = (first_nonzero_idx - 1) - zeros_count;
    
    // Add the leading 1s
    for (int k = 0; k < ones_count; k++) s += '1';
    // Add the 0s
    for (int k = 0; k < zeros_count; k++) s += '0';
    // Add the 1 we just found at 'first_nonzero_idx'
    s += '1';

    // Step 4: Find the remaining characters
    int prev_ans = zeros_count; 
    for (int i = first_nonzero_idx + 1; i <= n; i++) {
        int curr = ask(1, i);
        if (curr > prev_ans) {
            // Count increased, so we added a '1' (it formed pairs with existing 0s)
            s += '1';
        } else {
            // Count stayed same, so we added a '0'
            s += '0';
        }
        prev_ans = curr;
    }

    cout << "! " << s << endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
