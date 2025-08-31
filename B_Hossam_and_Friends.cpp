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
        int n,m;
        cin>>n>>m;
        vector<int> minRight(n, n);
        while(m--){
            int a,b;
            cin>>a>>b;
            --a;
            --b;
            if (a > b) swap(a, b);
            minRight[a] = min(minRight[a], b);
        }
        int ans = 0;
        int cur = n - 1;
        for(int l = n - 1; l >= 0; --l){
            cur = min(cur, minRight[l] - 1);
            ans += (cur - l + 1);
        }
        cout<<ans<<endl;
    }

    return 0;
}
