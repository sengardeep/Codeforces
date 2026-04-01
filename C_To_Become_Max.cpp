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
   int n,k;
   cin>>n>>k;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int mx=*max_element(all(v));
   int start=mx,end=mx+k;
   int ans=start;
   auto check = [&](int x) {
        for(int i = 0; i < n; i++) {
            int op = k;
            for(int j = 0; i + j < n; j++) {
                if(v[i + j] >= x - j) {
                    return 1; 
                }
                if(i + j == n - 1) {
                    break; 
                }
                
                int diff = (x - j) - v[i + j];
                if(diff > op) {
                    break; 
                }
                op -= diff;
            }
        }
        return 0;
    };
   while(start<=end){
    int mid = end + (start-end)/2;
    if(check(mid)){
        ans=mid;
        start=mid+1;
    }else end=mid-1;
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
