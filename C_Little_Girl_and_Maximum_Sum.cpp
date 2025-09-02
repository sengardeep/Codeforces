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
        vector<int> contribution(n,0);
        while(q--){
            int l,r;
            cin>>l>>r;
            --l;
            --r;
            contribution[l]+=1;
            if(r+1<n) contribution[r+1]-=1;
        }

        for(int i=1;i<n;i++) contribution[i]+=contribution[i-1];

        sort(begin(contribution),end(contribution));
        sort(begin(v),end(v));

        int ans=0;
        for(int i=0;i<n;i++) ans += (v[i]*contribution[i]);

        cout<<ans<<endl;
    }

    return 0;
}
