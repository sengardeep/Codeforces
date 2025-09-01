#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

struct FenwickTree
{
    int n;
    vector<long long> bit;

    FenwickTree(vector<long long> &v) : n((int)v.size()), bit(n + 1)
    {
        for (int i = 0; i < n; i++)
            update(i, v[i]);
    }

    void update(int i, long long x)
    {
        for (++i; i <= n; i += i & -i)
            bit[i] += x;
    }

    long long sum(int i)
    {
        long long s = 0;
        for (++i; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

    long long query(int l,int r){
        return sum(r)-sum(l-1);
    }
};
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,q;
    cin>>n>>q;
    vector<long long> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    FenwickTree ft(v);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int i,x;
            cin>>i>>x;
            --i;
            ft.update(i,x-v[i]);
            v[i] = x;
        }
        else{
            int l,r;
            cin>>l>>r;
            --l;
            --r;
            cout<<ft.query(l,r)<<endl;
        }
    }

    return 0;
}
