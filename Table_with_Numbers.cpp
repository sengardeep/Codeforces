#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
    int n,h,l;
    cin>>n>>h>>l;
    if(h>l) swap(h,l);
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(all(v));
    int ans=0;
    int i=0,j=n-1;
    while(i<j){
        int x=v[i],y=v[j];
        if(x<=h && y<=l) {
            ans++;
            i++;
            j--;
        }
        else if(y>l) j--;
        else if(x>h) break;
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
