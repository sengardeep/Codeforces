#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    vector<int> map(n+1);
    for(int i=0;i<m;i++) 
    {
        cin>>v[i]; 
        map[v[i]]++;
    }
    int start=1,end=m;
    int ans=m;
    auto f = [&](int t){
        int total=0;
        for(int i=1;i<=n;i++){
            int tasks = map[i];
            if(tasks <= t) 
            {
                total += tasks + (t-tasks)/2;
            }
            else total += t; 
        }
        if(total >= m) return 1;
        return 0;
    };
    while(start<=end){
        int mid = (start+end)/2;
        if(f(mid)){
            end=mid-1;
            ans=mid;
        }
        else start=mid+1;
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
