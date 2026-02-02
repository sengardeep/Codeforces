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
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> temp(n,1);
    for(int i=0;i+2<n;i++){
        if(v[i]>v[i+1] && (v[i+1]>v[i+2] || v[i+1]==v[i+2])) temp[i+2]=0;
        if(v[i]==v[i+1] && (v[i+1]>v[i+2] || v[i+1]==v[i+2])) temp[i+2]=0;
    }
    vector<int> pre(n,0);
    pre[0]=temp[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+temp[i];
    auto query = [&](int l,int r)->int{
        int ans=pre[r];
        return (l>0) ? (ans-pre[l-1]) : ans;
    };
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        int ans=query(l,r);
        if(temp[l]==0) ans++;
        if(l+1<=r && temp[l+1]==0) ans++;
        cout<<ans<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}