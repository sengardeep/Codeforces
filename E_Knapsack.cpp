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
    int x;
    cin>>x;
    vector<int> v(8);
    for(int i=0;i<8;i++) cin>>v[i];
    int ans=0;
    for(int mask=0;mask<(1<<8);mask++){
        int m=x;
        for(int i=0;i<8;i++){
            if(mask&(1<<i)){
                int w=i+1;
                m-=(min(m/w,v[i])*w);
            }
        }
        ans=max(ans,x-m);
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}