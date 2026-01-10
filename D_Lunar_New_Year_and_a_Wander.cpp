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
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    vector<int> vis(n+1,0);
    while(!pq.empty()){
        int node=pq.top();
        pq.pop();
        if(vis[node]) continue;
        vis[node]=1;
        cout<<node<<" ";
        for(auto it : adj[node]){
            if(vis[it]) continue;
            pq.push(it);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}