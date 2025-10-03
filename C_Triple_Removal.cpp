#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
struct SegTree {
    struct Node {
        int first, last;
        bool hasEqual;
    };

    int n;
    vector<Node> st;

    SegTree(): n(0) {}
    SegTree(const vector<int>& a) { init(a); }

    void init(const vector<int>& a) {
        n = (int)a.size();
        st.assign(n ? 4 * n : 0, {0,0,false});
        if (n) build(1, 0, n - 1, a);
    }

    Node merge(const Node& L, const Node& R) const {
        if (L.first == INT_MAX) return R; // identity for empty
        if (R.first == INT_MAX) return L;
        Node res;
        res.first = L.first;
        res.last = R.last;
        res.hasEqual = L.hasEqual || R.hasEqual || (L.last == R.first);
        return res;
    }

    void build(int p, int l, int r, const vector<int>& a) {
        if (l == r) {
            st[p] = {a[l], a[l], false}; // single element, no consecutive
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    bool query(int L, int R) const {
        if (n == 0 || L > R) return false;
        Node res = query(1, 0, n - 1, L, R);
        return res.hasEqual;
    }

    Node query(int p, int l, int r, int L, int R) const {
        if (R < l || r < L) return {INT_MAX, INT_MAX, false}; // identity
        if (L <= l && r <= R) return st[p];
        int m = (l + r) >> 1;
        return merge(query(p << 1, l, m, L, R),
                     query(p << 1 | 1, m + 1, r, L, R));
    }
};
void solve() {
   int n,q;
   cin>>n>>q;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> pre(n,0);
   pre[0]=v[0];
   for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];
   auto rangeSum = [&](int l,int r){
    if(l>0) return pre[r]-pre[l-1];
    else return pre[r];
   };
   SegTree seg(v);
   while(q--){
    int l,r;
    cin>>l>>r;
    --r;
    --l;
    int len = r-l+1,sum=rangeSum(l,r);
    if(len%3 || sum%3) cout<<-1<<endl;
    else{
        int ans=len/3;
        if(seg.query(l,r)) cout<<ans<<endl;
        else cout<<ans+1<<endl;
    }
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
   while(t--){
       solve();
   }

   return 0;
}
