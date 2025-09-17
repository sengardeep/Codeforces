#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin>>n;
    vector<pii> x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>x[i].first>>y[i].first;
        x[i].second=y[i].second=i;
    }
    sort(begin(x),end(x));
    sort(begin(y),end(y));
    auto area=[&](int mn_x,int mx_x,int mn_y,int mx_y){
        int h=mx_x-mn_x+1,w=mx_y-mn_y+1;
        if(h*w < n) return min(h*(w+1),(h+1)*w);
        return h*w;
    };
    int ans=area(x[0].first,x[n-1].first,y[0].first,y[n-1].first);
    if(n==1){
        cout<<ans<<endl;
        return;
    }
    set<int> ii = {x[0].second,x[n-1].second, y[0].second, y[n-1].second};
	for (int i : ii) {
        int mnx = x[0].second == i ? x[1].first : x[0].first;
        int mxx = x[n-1].second == i ? x[n-2].first : x[n-1].first;
        int mny = y[0].second == i ? y[1].first : y[0].first;
        int mxy = y[n-1].second == i ? y[n-2].first : y[n-1].first;
        ans = min(ans, area(mnx, mxx, mny, mxy));
    }
    cout<<ans<<endl;
}

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
       solve();
   }

   return 0;
}
