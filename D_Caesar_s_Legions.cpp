#include <bits/stdc++.h>
using namespace std;
 
int n1, n2, k1, k2, dp[101][101][11][11];
 
int c(int f, int h, int nf, int nh) {
	if (f > n1 || h > n2 || nf > k1 || nh > k2) return 0;
	if (f + h == n1 + n2) return 1;
	return (dp[f][h][nf][nh] != -1) ? dp[f][h][nf][nh] : (dp[f][h][nf][nh] = (c(f, h + 1, 0, nh + 1) + c(f + 1, h, nf + 1, 0)) % 100000000);
}
 
int main() {
	memset(dp, -1, sizeof dp);
	cin >> n1 >> n2 >> k1 >> k2;
	cout << c(0, 0, 0, 0);
}