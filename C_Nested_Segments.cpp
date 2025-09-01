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
        int n;
        cin>>n;
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++) cin>>v[i];
        
        vector<int> ans(n,-1);
        vector<int> dp(n+1,-1);
        n*=2;

        vector<int> segTree(4*n);

        auto merge = [](int a,int b){
            return a+b;
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

        function<int(int,int,int,int,int)> query=[&](int start,int end,int index,int l,int r)->int{
            if(end<l || start>r) return 0; //no overlap
            if(start>=l && end<=r) return segTree[index]; //Total overlap
            int mid=(start+end)/2;
            int left = query(start,mid,2*index,l,r);
            int right = query(mid+1,end,2*index+1,l,r);
            return left+right;
        };

        for(int i=0;i<n;i++){
            if(dp[v[i]] == -1) dp[v[i]]=i;
            else{
                int l=dp[v[i]],r=i;
                // cerr<<l<<" "<<r<<endl;
                ans[v[i]-1]=query(0,n-1,1,l,r);
                update(0,n-1,1,l,1);
            }
        }

        for(auto it : ans) cout<<it<<" ";
    }

    return 0;
}
