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
    vector<pii> v(n);
    map<pii,int> map;
    int ans1=-1,ans2=-1;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
        if(map.count(v[i])){
            ans1=i+1;
            ans2=map[v[i]];
        } 
        map[v[i]]=i+1;
    }
    if(ans1!=-1 && ans2!=-1){
        cout<<ans1<<" "<<ans2;
        return;
    }
    sort(all(v),[&](pii&a,pii&b){
        return (a.first==b.first)?(a.second>b.second):(a.first<b.first);
    });

    int mx=0;
    for(auto [l,r] : v){
        if(r<=mx) {
            ans1=map[{l,r}];
            break;
        }
        mx=max(mx,r);
    }
    if(ans1==-1){
        cout<<-1<<" "<<-1;
        return;
    }
    for(int i=0;i<n;i++){
        if(v[i].second==mx) {
            ans2=map[v[i]];
            break;
        }
    }
    cout<<ans1<<" "<<ans2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}