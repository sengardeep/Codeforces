#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

struct  Node{
    int sum;
    int mx;
    int pre;
    int suf;
};

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

        vector<Node> segTree(4*n);
        function<void(int,int,int)> build=[&](int start,int end,int index)->void{
            if(start==end){
            int x=0;
            segTree[index].sum=v[start];
            segTree[index].mx=max(v[start],x);
            segTree[index].pre=max(v[start],x);
            segTree[index].suf=max(v[start],x);
            return;
            }

            int mid = (start+end)/2;
            build(start,mid,2*index);
            build(mid+1,end,2*index+1);
            segTree[index].sum=segTree[2*index].sum+segTree[2*index+1].sum;
            segTree[index].mx=max({segTree[2*index].mx,segTree[2*index+1].mx,segTree[2*index].suf+segTree[2*index+1].pre});
            segTree[index].pre=max({segTree[2*index].pre,segTree[2*index].sum+segTree[2*index+1].pre});
            segTree[index].suf=max({segTree[2*index+1].suf,segTree[2*index].suf+segTree[2*index+1].sum});
        };

        function<void(int,int,int,int,int)> update=[&](int start,int end,int index,int pos,int val)->void{
            if(start==end){
            int x=0;
            segTree[index].sum=val;
            segTree[index].mx=max(x,val);
            segTree[index].pre=max(x,val);
            segTree[index].suf=max(x,val);
            return;
            }
            int mid=(start+end)/2;
            if(pos <= mid) update(start,mid,2*index,pos,val);
            else update(mid+1,end,2*index+1,pos,val);
            segTree[index].sum=segTree[2*index].sum+segTree[2*index+1].sum;
            segTree[index].mx=max({segTree[2*index].mx,segTree[2*index+1].mx,segTree[2*index].suf+segTree[2*index+1].pre});
            segTree[index].pre=max({segTree[2*index].pre,segTree[2*index].sum+segTree[2*index+1].pre});
            segTree[index].suf=max({segTree[2*index+1].suf,segTree[2*index].suf+segTree[2*index+1].sum});
        };

        build(0,n-1,1);
        cout<<segTree[1].mx<<endl;
        while(q--){
            int i,val;
            cin>>i>>val;
            update(0,n-1,1,i,val);
            cout<<segTree[1].mx<<endl;
        }


    }

    return 0;
}
