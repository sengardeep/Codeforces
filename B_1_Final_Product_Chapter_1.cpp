#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<2*n-1;i++) cout<<1<<" ";
    cout<<b<<endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}