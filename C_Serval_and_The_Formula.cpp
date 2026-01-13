#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back
#define all(v) v.begin(), v.end()

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0,j=-1;
    for(int i=0;i<31;i++){
        if((a&(1<<i)) && (b&(1<<i))){
            if(j==-1){
                a+=(1LL<<i);
                b+=(1LL<<i);
                ans|=(1LL<<i);
            }else{
                for(int k=j;k<i;k++) {
                    a+=(1LL<<k);
                    b+=(1LL<<k);
                    ans|=(1LL<<k);
                }
                j=i;
            }
        }else if((a&(1LL<<i)) || (b&(1LL<<i))) j=i;
    }
    cout<<ans<<endl;
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
