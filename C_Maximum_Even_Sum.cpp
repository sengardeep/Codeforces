#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

void solve()
{
    int a, b;
    cin >> a >> b;
    if(a%2 && b%2) cout<<a*b+1<<endl;
    else{
        if(b%2==0){
            if((a*b/2 + 2)%2==0) cout<<(a*b/2 + 2)<<endl;
            else cout<<-1<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
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
