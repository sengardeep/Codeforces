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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> segTree(4*n);

        auto merge = [](int a,int b){
            return max(a,b);
        };
        function<void(int,int,int)> build=[&](int start,int end,int index)->void{
            if(start==end){
                segTree[index]=v[start];
                return;
            }

            int mid=(start+end)/2;
            build(start,mid,2*index);
            build(mid+1,end,2*index+1);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };

        function<void(int,int,int,int,int)> update=[&](int start,int end, int index,int pos,int val)->void{
            if(start==end){
                segTree[index]=val;
                return;
            }

            int mid=(start+end)/2;
            if(pos<=mid) update(start,mid,2*index,pos,val);
            else update(mid+1,end,2*index+1,pos,val);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };

        function<int(int,int,int,int)> query=[&](int start,int end,int index,int x)->int{
            if(segTree[index]<x) return -1;
            if(start==end) return start;

            int mid=(start+end)/2;
            if(segTree[2*index]>=x) return query(start,mid,2*index,x);
            else return query(mid+1,end,2*index+1,x);
        };

        build(0,n-1,1);
        while(q--){
            int x;
            cin>>x;
            if(x==1){
                int pos,val;
                cin>>pos>>val;
                update(0,n-1,1,pos,val);
            }
            else{
                int x;
                cin>>x;
                cout<<query(0,n-1,1,x)<<endl;
            }
        }
    }
    return 0;
}