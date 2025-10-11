#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl;
//Strongly Connected Components(SCC)
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> tadj[n+1];//Reverse Graph
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        tadj[v].pb(u);
    }
    vector<int> vis(n+1,0);
    stack<int> st;
    //Kind of Topo
    function<void(int)> dfs=[&](int node)->void{
        vis[node]=1;
        for(auto child : adj[node]) if(vis[child]==0) dfs(child);
        st.push(node);
    };
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    fill(begin(vis),end(vis),0);
    vector<vector<int>> scc;
    vector<int> temp;
    function<void(int)> dfs2=[&](int node)->void{
        vis[node]=1;
        temp.pb(node);
        for(auto child : tadj[node]) if(vis[child]==0) dfs2(child);
    };
    while(!st.empty()){
        int node=st.top(); st.pop();
        if(vis[node]) continue;
        dfs2(node);
        scc.pb(temp);
        temp.clear();
    }
    if(scc.size()==1){
        cout<<"YES";
        return;
    }
    cout<<"NO"<<endl;
    cout<<scc[1].back()<<" "<<scc[0].back();
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
    