#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod=1e9+7;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,vector<int>> map;
    for(int i=0;i<n;i++) map[v[i]-i].pb(v[i]);
    int ans=0;
    for(auto [x,a] : map){
        int sum=accumulate(all(a),0LL);
        ans=max(ans,sum);
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}