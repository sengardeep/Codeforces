#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << " = " << (x) << endl
const int mod=1e9+7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    map<string,int> map;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]==0 && b[i]==0) ans++;
        else if(a[i]==0) continue;
        else {
            int g=gcd(a[i],b[i]);
            a[i]/=g;
            b[i]/=g;
            string s=to_string(b[i]);
            s+='/';
            s+=to_string(a[i]);
            map[s]++;
        }
    }
    int mx=0;
    for(auto [x,f] : map) mx=max(mx,f);
    ans+=mx;
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}