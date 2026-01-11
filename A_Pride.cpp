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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    int one=0;
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
        one+=(v[i]==1);
    }
    if(one){
        cout<<n-one;
        return;
    }
    int ans=1e9;
    for(int i=0;i<n;i++){
        int g=0;
        for(int j=i;j<n;j++) 
        {
            g=gcd(g,v[j]);
            if(g==1) {
                ans=min(ans,j-i);
                break;
            }
        }
    }
    if(ans==1e9) cout<<-1;
    else cout<<ans+n-1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}