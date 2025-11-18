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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    vector<pii> map;
    for(int i=0;i<n;i++) map.push_back({v[i], i});
    sort(begin(map),end(map));

    int last = map.back().second;
    vector<int> right(n), left(n);
    for(int i=0;i<n;i++){
        right[i] = (i+1)%n;
        left[i] = (i-1+n)%n;
    }
    int ans = 0;
    for(auto [num,idx] : map){
        if(idx==last) continue;
        int l=left[idx],r=right[idx];
        ans += min(v[l], v[r]);
        right[l] = r;
        left[r] = l;
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
