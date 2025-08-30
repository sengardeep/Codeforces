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
    // cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> v(n,1);
        vector<int> segTree(4 * n + 1,0);
        vector<int> lazy(4 * n + 1 , 1);
        
        auto merge = [&](int a,int b) {return (a+b)%mod;};

        auto push = [&](int index){
            if(lazy[index]!=1){
                lazy[2*index] = (lazy[2*index] * lazy[index]) % mod;
                lazy[2*index+1] = (lazy[2*index+1] * lazy[index]) % mod;
                segTree[2*index] = (segTree[2*index]*lazy[index])%mod;
                segTree[2*index+1] = (segTree[2*index+1]*lazy[index])%mod;
                lazy[index]=1;
            }
        };

        function<void(int,int,int)> build = [&](int start,int end,int index)->void{
            if(start==end) {
                segTree[index]=v[start];
                return;
            }
            int mid=(start+end)/2;
            build(start,mid,2*index);
            build(mid+1,end,2*index+1);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
            return;
        };

        function<void(int,int,int,int,int,int)> update = [&](int start,int end,int index,int l,int r,int val)->void{
            if(r < start || end < l) return;

            if(l <= start && end <= r){
                val %= mod;
                segTree[index] = (segTree[index]*val)%mod;
                lazy[index] = (lazy[index]*val)%mod;
                return;
            }

            int mid=(start+end)/2;
            if(start != end) push(index);
            update(start,mid,2*index,l,r,val);
            update(mid+1,end,2*index+1,l,r,val);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };

        function<int(int,int,int,int,int)> query = [&](int start, int end, int index, int l, int r)->int
        {
            if(r < start || end < l) return 0;
            if(l <= start && end <= r) return segTree[index];

            int mid = (start + end) / 2;
            if(start != end) push(index);
            int leftAns = query(start, mid, 2 * index, l, r);
            int rightAns = query(mid + 1, end, 2 * index + 1, l, r);

            return merge(leftAns, rightAns);
        };

        build(0,n-1,1);
        while(q--){
            int x;
            cin>>x;
            if(x==1){
                int l,r,val;
                cin>>l>>r>>val;
                update(0,n-1,1,l,r-1,val);
            }
            else{
                int l,r;
                cin>>l>>r;
                cout<<query(0,n-1,1,l,r-1)<<endl;
            }
        }

    }

    return 0;
}
