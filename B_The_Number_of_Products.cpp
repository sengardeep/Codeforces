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
    vector<int> v(n),negId;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]<0) v[i]=-1;
        else v[i]=1;
    }
    vector<int> pre(n,1);
    pre[0]=v[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]*v[i];
    int pos=count(all(pre),1),neg=n-pos;
    int ans1=pos,ans2=neg;
    for(int i=1;i<n;i++){
        if(v[i-1]>0) pos--;
        else {
            neg--;
            swap(pos,neg);
        }
        ans1+=pos;
        ans2+=neg;
    }
    cout<<ans2<<" "<<ans1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}