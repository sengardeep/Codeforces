#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl;

void solve() {
    int n;
    cin>>n;
    vector<int> segTee(4*n,0);
    function<void(int,int,int,int)> update=[&](int start,int end,int index,int pos)->void{
        if(start==end) {
            segTee[index]=1;
            return;
        }

        int mid=(start+end)/2;
        if(pos <= mid) update(start,mid,2*index,pos);
        else update(mid+1,end,2*index+1,pos);
        segTee[index]=segTee[2*index]+segTee[2*index+1];
    };
    function<int(int,int,int,int,int)> query=[&](int start,int end,int index,int l,int r)->int{
        if(l>end || r<start) return 0;
        if(start>=l&&end<=r) return segTee[index];
        int mid = (start+end)/2;
        return query(start,mid,2*index,l,r)+query(mid+1,end,2*index+1,l,r);
    };
    vector<int> v(n);
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
        cout<<query(0,n-1,1,v[i]-1,n-1)<<" ";
        update(0,n-1,1,v[i]-1);
    }

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
    