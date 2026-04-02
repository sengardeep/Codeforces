#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;

    bool dp[2] = {true, false}; 

    for (int i = 0; i < n; i++) {
        int rem = n - i;
        bool ndp[2] = {false, false};

        for (int s = 0; s < 2; s++) {
            if (!dp[s]) continue;

            char left = (s == 0 ? 'a' : 'b');
            char right;
            if (rem % 2 == 1) right = left;                  // odd length -> same ends
            else right = (left == 'a' ? 'b' : 'a');         // even length -> opposite ends

            if (x[i] == '?' || x[i] == left) {
                ndp[s ^ 1] = true; // remove left
            }
            if (x[i] == '?' || x[i] == right) {
                ndp[s] = true;     // remove right
            }
        }

        dp[0] = ndp[0];
        dp[1] = ndp[1];
    }

    cout << (dp[0] || dp[1] ? "Yes" : "No") << endl;
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
