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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        vector<int> temp(k);
        for(int j=0;j<k;j++) cin>>temp[j];
        v.pb(temp);
    }
    vector<int> parent(n+1),size(n+1,1);
    for(int i=1;i<=n;i++) parent[i]=i;
    function<int(int)> find=[&](int u)->int{
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    };
    auto unite=[&](int a,int b){
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };
    for(int i=0;i<m;i++){
        for(size_t j=0;j+1<v[i].size();j++){
            unite(v[i][j], v[i][j+1]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<size[find(i)]<<" ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}