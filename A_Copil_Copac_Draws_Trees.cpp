#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> adj[n];
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(0);
        vector<int> ans(n,-1);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                ans[node]=count;
                for(auto it : adj[node]){
                    if(it != node && ans[it] == -1) q.push(it);
                }
            }
            count++;
        }

        // for(auto it : ans) cerr<<it<<" ";
        // cerr<<endl;
        cout<<*max_element(ans.begin(),ans.end())-1<<endl;
    }

    return 0;
}
