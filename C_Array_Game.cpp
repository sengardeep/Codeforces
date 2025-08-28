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
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        if(k>2){
            cout<<0<<endl;
            continue;
        }
        sort(begin(v),end(v));
        int ans=1e18;
        for(int i=0;i<n-1;i++){
            ans=min({ans,v[i],v[i+1]-v[i]});
        }
        if(k==1){
            cout<<ans<<endl;
        }
        else{
            for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
            int diff = v[i] - v[j];
            int idx = lower_bound(begin(v), end(v), diff) - begin(v);
            if (idx < n) ans = min(ans, v[idx] - diff);
            if (idx > 0) ans = min(ans, diff - v[idx - 1]);
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
