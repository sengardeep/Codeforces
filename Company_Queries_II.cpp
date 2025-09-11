#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
// ----------- Sparse Table Template -----------
//While using SparseTable , Always think about Binary Search
struct SparseTable {
    int n, LOG;
    vector<vector<int>> st;
    vector<int> lg;
    vector<int> arr;  // Store the array for comparisons

    SparseTable(const vector<int>& input_arr) {
        arr = input_arr;
        n = arr.size();
        LOG = 32 - __builtin_clz(n);   // ceil(log2(n))
        st.assign(n, vector<int>(LOG+1));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

        for (int i = 0; i < n; i++) st[i][0] = i;

        for (int k = 1; k <= LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                int left = st[i][k-1];
                int right = st[i + (1 << (k-1))][k-1];
                st[i][k] = (arr[left] <= arr[right]) ? left : right;
            }
        }
    }

    int query(int l, int r) {  // inclusive [l, r], returns index of minimum
        int k = lg[r - l + 1];
        int left = st[l][k];
        int right = st[r - (1 << k) + 1][k];
        return (arr[left] <= arr[right]) ? left : right;
    }
};
// ----------- End of Sparse Table -----------

void solve() {
   int n,q;
   cin>>n>>q;
   vector<int> adj[n+1];
   for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[i].push_back(x);
    adj[x].push_back(i);
   }
   //Euler Tour (type-1) (LCA)
   vector<int> flat;
   map<int,int> map; //Storing the first index
   int idx=0;
   vector<int> level(n+1);
   function<void(int,int)> dfs=[&](int node,int par)->void{
    if(!map.count(node)){
        map[node]=idx;
    }
    flat.push_back(node);
    idx++;
    for(auto child : adj[node]){
        if(child==par) continue;
        level[child]=level[node]+1;
        dfs(child,node);
        flat.push_back(node);
        idx++;
    }
   };
   dfs(1,0);
   vector<int> arr(flat.size()); //For range queries on it
   for(int i=0;i<flat.size();i++){
    arr[i]=level[flat[i]];
   }
   SparseTable st = SparseTable(arr);
   while(q--){
    int a,b;
    cin>>a>>b;
    //Find the indexes of a and b
    int idx1=map[a],idx2=map[b];
    if(idx1>idx2) swap(idx1,idx2);
    int idx = st.query(idx1,idx2);
    cout<<flat[idx]<<endl;
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
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
