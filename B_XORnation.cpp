#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    int total = n + 1,ans=0;
    for (int i = 0; (1LL << i) <= n; i++)
    {
        int c0 = 0;
        if (i == 0)
        {
            int q = total / 4;
            int r = total % 4;
            c0 = q * 2LL + min(r, 2LL);
        }
        else
        {
            int L = 1LL << i;                                
            int P = L << 1;                                  
            int m = total / P;                              
            int rem = total % P;                            
            int z1 = min<int>(rem, L + 1);                   
            int z2len = rem > (L + 1) ? (rem - (L + 1)) : 0; 
            int per = (L / 2) * 3;                           
            c0 = (int)m * per + z1 + (z2len / 2);         
        }
        int c1 = (int)total - c0;
        int pairsMod = (int)((c0 % mod) * (c1 % mod) % mod);
        int bit = (1LL << i) % mod;
        ans = (ans + pairsMod * bit) % mod;
    }

    cout << ans % mod << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
