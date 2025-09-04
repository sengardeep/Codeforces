#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

// Credits to HealthyUG for the inspiration.
// Lazy Segment Tree with Range Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime
template<typename Node, typename Update>
struct LazySGT {
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<int> &arr; // reference to original array
    int n;
    int s;
    bool materialized; // whether we've pushed values to the original array

    LazySGT(int a_len, vector<int> &a) : arr(a) { // keep reference to original
        n = a_len;
        s = 1;
        while (s < 2 * n) s <<= 1;
        tree.assign(s, Node());
        lazy.assign(s, false);
        updates.assign(s, Update());
        materialized = false;
        if (n > 0) build(0, n - 1, 1);
    }
    
    void build(int start, int end, int index) {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void pushdown(int index, int start, int end){
        if(lazy[index]){
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(int index, int start, int end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update& u) {
        if(start > right || end < left) return;
        if(start >= left && end <= right){
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) {
        if (start > right || end < left) return Node();
        if (start >= left && end <= right){
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, int val) {
        Update new_update = Update(val);
        update(0, n - 1, 1, left, right, new_update);
        materialized = false; // further updates invalidate materialization
    }
    // Push all lazy updates to leaves and write values to original array
    void push_all(int index, int start, int end){
        if(start == end){
            // ensure any pending leaf update is applied
            if(lazy[index]){
                Update tmp = updates[index];
                apply(index, start, end, tmp);
                updates[index] = Update();
                lazy[index] = false;
            }
            arr[start] = tree[index].val;
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        push_all(2 * index, start, mid);
        push_all(2 * index + 1, mid + 1, end);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void materialize_array(){
        if(materialized || n == 0) return;
        push_all(1, 0, n - 1);
        materialized = true;
    }
    Node make_query(int left, int right) {
        // Ensure original array reflects all updates at first query
        materialize_array();
        return query(0, n - 1, 1, left, right);
    }
};
struct Node1 {
    int val;
    Node1() { // Identity element for AND
        val = (1<<30)-1;
    }
    Node1(int p1) {
        val = p1;
    }
    void merge(Node1 &l, Node1 &r) {
        val = l.val & r.val;
    }
};
struct Update1 {
    int val;
    Update1(){
        val = 0;
    }
    Update1(int val1) {
        val = val1;
    }
    void apply(Node1 &a, int start, int end) {
        a.val |= val;
    }
    void combine(Update1& new_update, int start, int end){
        val |= new_update.val;
    }
};


int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    vector<tuple<int,int,int>> queries;
    LazySGT<Node1,Update1> segTree = LazySGT<Node1,Update1>(n,v);
    while(m--){
        int l,r,x;
        cin>>l>>r>>x;
        queries.push_back({l-1,r-1,x});
        segTree.make_update(l-1,r-1,x);
    }
    // auto f = [](int n){
    //     int ans=0;
    //     while(1<<(ans+1) <= n) ans++;
    //     return ans;
    // };
    // int LOG = f(n);
    // vector<vector<int>> st(n,vector<int>(LOG+1));
    // st[0][0]=v[0];
    // for(int i=1;i<n;i++) 
    // {
    //     v[i] |= v[i-1];
    //     st[i][0]=v[i];
    // }
    // for(int j=1;j<=LOG;j++) for(int i=0;i+(1<<j)-1<n;i++) st[i][j]=st[i][j-1] & st[i+(1<<(j-1))][j-1];
    // auto query = [&](int L,int R){
    //     int len = (R-L+1);
    //     int k = f(len);

    //     return st[L][k] & st[R-(1<<k)+1][k];
    // };

    bool flag=true;
    for(auto it : queries){
        int l = get<0>(it);
        int r = get<1>(it);
        int x = get<2>(it);
        if(segTree.make_query(l,r).val != x) {
            // cerr<<query(l,r)<<" ";
            flag=false;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
        for(auto it : v) cout<<it<<" ";
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
