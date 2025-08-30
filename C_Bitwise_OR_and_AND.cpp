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

        vector<int> segTree(4*n);
        vector<int> lazy(4*n);
        auto merge = [&](int a,int b){
            return (a&b);
        };

        auto propogate = [&](int start,int end,int index){
            if(start==end){
                lazy[index]=0;
                return;
            }
            lazy[2*index] |= lazy[index];
            lazy[2*index+1] |= lazy[index];
            lazy[index]=0;
            return;
        };

        function<void(int,int,int,int,int,int)> update = [&](int start,int end,int index,int l,int r,int val)->void{
            if(lazy[index] != 0) {
                segTree[index] |= lazy[index];
                propogate(start,end,index);
            }
            if(l>end || r<start) return;
            if(start>=l && end<=r){
                segTree[index] |= val;
                lazy[index] |= val;
                return;
            } 
            int mid=(start+end)/2;
            update(start,mid,2*index,l,r,val);
            update(mid+1,end,2*index+1,l,r,val);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };

        function<int(int,int,int,int,int)> query = [&](int start,int end,int index,int l,int r)->int{
            if(lazy[index] != 0) {
                segTree[index] |= lazy[index];
                propogate(start,end,index);
            }
            if(l>end || r<start) return ((1LL<<30)-1);
            if(start >= l && end <= r) return segTree[index];
            int mid = (start+end)/2;
            int left = query(start,mid,2*index,l,r);
            int right = query(mid+1,end,2*index+1,l,r);
            return merge(left,right);
        };

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
