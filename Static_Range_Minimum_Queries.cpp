#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

int f(int n){
    int ans=0;
    while(1<<(ans+1) <= n) ans++;
    return ans;
}
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
        int LOG = f(n);
        vector<vector<int>> st(n,vector<int>(LOG+1));
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            st[i][0]=v[i];
        }

        //PreProcessing
        for(int j=1;j<=LOG;j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }

        //query
        function<int(int,int)> query=[&](int L,int R)->int{
            int len = R-L+1;
            int k = f(len);
            return min(st[L][k],st[R-(1<<k)+1][k]);
        };

        while(q--){
            int l,r;
            cin>>l>>r;
            --l;
            --r;
            cout<<query(l,r)<<endl;
        }


    }

    return 0;
}
