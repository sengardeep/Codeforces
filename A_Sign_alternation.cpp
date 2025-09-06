#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

template <typename Node, typename Update>
struct SegTree
{
    vector<Node> tree;
    vector<int> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<int> &a)
    { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n)
        {
            s = s << 1;
        }
        tree.resize(s);
        fill(tree.begin(), tree.end(), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) // Never change this
    {
        if (start == end)
        {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u) // Never Change this
    {
        if (start == end)
        {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, int val)
    {                                    // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right)
    {
        return query(0, n - 1, 1, left, right);
    }
};
struct Node1
{
    int val; // may change
    Node1()
    {            // Identity element
        val = 0; // may change
    }
    Node1(int p1)
    {             // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r)
    {                          // Merge two child nodes
        val = (l.val + r.val); // may change
    }
};
struct Update1
{
    int val; // may change
    Update1(int p1)
    {             // Actual Update
        val = p1; // may change
    }
    void apply(Node1 &a)
    { // apply update to given node
        if (a.val < 0)
            a.val = -val;
        else
            a.val = val; // may change
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)~
    {
        int x;
        cin >> x;
        v1[i]=v2[i]=x;
        if(i&1) v2[i]=-x;
        else v1[i]=-x; 
    }
    SegTree<Node1,Update1> segTree1 = SegTree<Node1,Update1>(n,v1);
    SegTree<Node1,Update1> segTree2 = SegTree<Node1,Update1>(n,v2);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type == 1) {
            int l,r;
            cin>>l>>r;
            --l;--r;
            if(l&1) cout<<segTree1.make_query(l,r).val<<endl;
            else cout<<segTree2.make_query(l,r).val<<endl;
        }
        else{
            int i,val;
            cin>>i>>val;
            segTree1.make_update(i-1,val);
            segTree2.make_update(i-1,val);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
