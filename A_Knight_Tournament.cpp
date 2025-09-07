#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct SegTree {
    int n;
    vector<int> seg, lazy;

    SegTree(int n): n(n) {
        seg.assign(4*n, 0);
        lazy.assign(4*n, -1); // -1 means no pending update
    }

    void push(int idx, int l, int r) {
        if(lazy[idx] == -1) return;
        int val = lazy[idx];
        seg[idx] = (r - l + 1) * val;
        if(l != r) {
            if(lazy[2*idx] == -1) lazy[2*idx] = val;
            if(lazy[2*idx+1] == -1) lazy[2*idx+1] = val;
        }
        lazy[idx] = -1;
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        push(idx,l,r);
        if(r < ql || l > qr) return;
        if(l >= ql && r <= qr) {
            if(seg[idx] == 0) { // unassigned
                lazy[idx] = val;
                push(idx,l,r);
            }
            return;
        }
        int mid = (l+r)/2;
        update(2*idx,l,mid,ql,qr,val);
        update(2*idx+1,mid+1,r,ql,qr,val);
        seg[idx] = seg[2*idx] + seg[2*idx+1];
    }

    int query(int idx, int l, int r, int pos) {
        push(idx,l,r);
        if(l==r) return seg[idx];
        int mid = (l+r)/2;
        if(pos <= mid) return query(2*idx,l,mid,pos);
        else return query(2*idx+1,mid+1,r,pos);
    }
};

void solve() {
    int n,q; cin>>n>>q;
    SegTree st(n);
    while(q--) {
        int l,r,x;
        cin>>l>>r>>x;
        l--, r--, x--;
        if(l <= x-1) st.update(1,0,n-1,l,x-1,x+1);
        if(x+1 <= r) st.update(1,0,n-1,x+1,r,x+1);
    }
    for(int i=0;i<n;i++) cout<<st.query(1,0,n-1,i)<<" ";
    cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
