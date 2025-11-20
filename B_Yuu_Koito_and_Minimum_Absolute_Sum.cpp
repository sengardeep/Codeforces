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
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    bool flag1 = (v[0]==-1);
    bool flag2 = (v[n-1]==-1);
    if(flag1 && flag2) {
        v[0]=0;
        v[n-1]=0;
    } else if(flag1) {
        v[0]=v[n-1];
    } else if(flag2) {
        v[n-1]=v[0];
    }
    for(int i=1;i<n-1;i++) if(v[i]==-1) v[i]=0;
    int ans = abs(v[n-1]-v[0]);
    cout << ans << endl;
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    cout << endl;
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
