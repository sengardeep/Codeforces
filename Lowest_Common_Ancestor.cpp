#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

void solve() {
   int n;
   cin>>n;
   vector<int> adj[n+1];
   for(int i=1;i<=n;i++){
    int m;
    cin>>m;
    while(m--){
        int v;
        cin>>v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
   }

   //Find the kth parent
    vector<vector<int>> parent(n+1,vector<int>(17,0));
    vector<int> level(n+1);
    function<void(int,int,int)> dfs = [&](int node,int par,int l=0)->void{
        parent[node][0]=par;
        level[node]=l;
        //PreProcessing 
        for(int i=1;i<=16;i++){
            parent[node][i]=parent[parent[node][i-1]][i-1]; //If not exist then 0(Garbage)
        }
        for(auto child : adj[node]){
            if(child == par) continue;
            dfs(child,node,l+1);
        }
        return;
    };
    dfs(1,0,0);
    auto kthPar = [&](int node,int k){
        int cnt=0;
        while(k){
            if(k&1){
                node=parent[node][cnt];
            }
            cnt++;
            k>>=1;
        }
        return node;
    };
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        //Find the LCA of a and b
        if(level[a]>level[b]) swap(a,b);
        int k=level[b]-level[a];
        //Move a to level b
        b=kthPar(b,k);
        if(a==b){
            cout<<a<<endl;
            continue;
        }
        int ans=1;
        int start=0,end=level[a];
        while(start<=end){
            int mid = (start+end)/2;
            int aP=kthPar(a,mid),bP=kthPar(b,mid);
            if(aP==bP){
                ans=aP;
                end=mid-1;
            }
            else start=mid+1;
        }
        
        cout<<ans<<endl;
    }
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
   cin>>t;
   for(int i=1;i<=t;i++){
    cout<<"Case "<<i<<":"<<endl;
       solve();
   }

   return 0;
}
