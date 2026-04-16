#include <bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randll(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng);
}

ll solve(ll N, ll S, ll M, ll L){
    ll ans = 1e18;

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            ll eggs = 6LL*i + 8LL*j;
            ll rem = max(0LL, N - eggs);
            ll k = (rem + 11) / 12;

            ll cost = (i*S + j*M + k*L)%(1000000007);
            ans = min(ans, cost);
        }
    }

    return ans;
}

int main(){
    // ----------------------------
    // Generate Test Case
    // ----------------------------
    freopen("input.txt","w",stdout);

    ll N = randll(1, 100);
    ll S = randll(1, 1000);
    ll M = randll(1, 1000);
    ll L = randll(1, 1000);

    cout << N << " " << S << " " << M << " " << L << "\n";

    fclose(stdout);

    // ----------------------------
    // Solve and Output
    // ----------------------------
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> N >> S >> M >> L;

    cout << solve(N, S, M, L) << "\n";

    fclose(stdin);
    fclose(stdout);

    return 0;
}