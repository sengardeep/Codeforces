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
    int start=1,end=n;
    int i=0,j=1;
    while(j<k){
        int idx=i;
        while(idx<n) {
            v[idx]=end--;
            idx+=k;
        }
        idx=j;
        while(idx<n){
            v[idx]=start++;
            idx+=k;
        }
        i+=2;
        j+=2;
    }   
    for(auto x : v) cout<<x<<" ";
    cout<<endl;
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
