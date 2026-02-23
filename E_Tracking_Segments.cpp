#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

class SegmentTree {
    vector<int> tree;
    int n;
    
    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node] = 1;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx);
            else
                update(2 * node + 1, mid + 1, end, idx);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + 
               query(2 * node + 1, mid + 1, end, l, r);
    }
    
public:
    SegmentTree(int sz) : n(sz), tree(4 * sz, 0) {}
    
    void update(int idx) { update(1, 1, n, idx); }
    
    int query(int l, int r) { return query(1, 1, n, l, r); }
};

void solve() {
   int n,m;
   cin>>n>>m;
   vector<pii> upd(m);
   for(int i=0;i<m;i++) cin>>upd[i].first>>upd[i].second;
   int q;
   cin>>q;
   vector<int> queries(q);
   for(int i=0;i<q;i++) cin>>queries[i];
   auto check=[&](int k){
    SegmentTree st(n);
    for(int i=0;i<k;i++){
        int index=queries[i];
        st.update(index);
    }
    for(int i=0;i<m;i++){
        auto [l,r] = upd[i];
        int sum=st.query(l,r);
        int rem=(r-l+1)-sum;
        if(sum>rem) return 1;
    }
    return 0;
   };
   int ans=-1,start=1,end=q;
   while(start<=end){
    int mid=(start+end)/2;
    if(check(mid)){
        ans=mid;
        end=mid-1;
    }else start=mid+1;
   }
   cout<<ans<<endl;
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
   while(t--){
       solve();
   }

   return 0;
}
