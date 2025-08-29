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
        int m=(1<<n);
        vector<int> v(m);
        for(int i=0;i<m;i++) cin>>v[i];
        vector<int> segTree(4*m);

        auto merge1 = [](int a,int b){
            return a|b;
        };
        auto merge2 = [](int a,int b){
            return a^b;
        };
        int flag=0;
        
        function<void(int,int,int)> build=[&](int start,int end,int index)->void{
            if(start==end){
                segTree[index]=v[start];
                flag=1;
                return;
            }

            int mid=(start+end)/2;
            build(start,mid,2*index);
            build(mid+1,end,2*index+1);
            if(flag){
                flag^=1;
                segTree[index]=merge1(segTree[2*index],segTree[2*index+1]);
            }
            else {
                flag^=1;
                segTree[index]=merge2(segTree[2*index],segTree[2*index+1]);
            }
        };
        function<void(int,int,int,int,int)> update=[&](int start,int end, int index,int pos,int val)->void{
            if(start==end){
                segTree[index]=val;
                flag=1;
                return;
            }

            int mid=(start+end)/2;
            if(pos<=mid) update(start,mid,2*index,pos,val);
            else update(mid+1,end,2*index+1,pos,val);
            if(flag){
                flag^=1;
                segTree[index]=merge1(segTree[2*index],segTree[2*index+1]);
            }
            else {
                flag^=1;
                segTree[index]=merge2(segTree[2*index],segTree[2*index+1]);
            }
        };
        build(0,m-1,1);
        while(q--){
            int pos,val;
            cin>>pos>>val;
            pos--;
            // flag=1;
            update(0,m-1,1,pos,val);
            cout<<segTree[1]<<endl;
        }
    }

    return 0;
}
