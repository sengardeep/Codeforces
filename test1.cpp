#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000009;

int dp[100100][64];

signed main() {
    int n;
    cin >> n;
 
    vector<int> vec(n+1);
    for(int i = 1; i <= n; i++) cin >> vec[i];
 
   	dp[0][0] = 1;
 
   	for(int i = 1; i <= n; i++){
   		for(int j = 0; j < 64; j++){
   			int x = dp[i - 1][j];
   			int y = dp[i - 1][j & vec[i]];
 
   			dp[i][j] = (x + y) % mod;
   		}
   	}
 
   	cout << dp[n][63] << endl;
}