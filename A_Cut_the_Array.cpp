#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), pre(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
        pre[i] = sum;
    }
    for(int i = 0; i < n-2; i++){
        int sum1 = pre[i];
        for(int j = i+1; j < n-1; j++){
            int sum2 = pre[j] - sum1;
            int sum3 = sum - (sum1 + sum2);
            if((sum1 % 3) == (sum2 % 3) && (sum1 % 3) == (sum3 % 3)){
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
            if((sum1 % 3) != (sum2 % 3) && (sum1 % 3) != (sum3 % 3) && (sum2 % 3) != (sum3 % 3)){
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }
    }
    cout<<"0 0"<<endl;
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
