#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> divisors;
   for(int i=1;i*i<=n;i++){
    if((n%i)==0){
        divisors.pb(i);
        if(n/i != i) divisors.pb(n/i);
    }
   }
   int ans=0;
   for(auto d : divisors){
    int g=0;
    for(int i=0;i<d;i++){
        int j=i;
        while((j+d)<n){
            g=gcd(g,abs(v[j]-v[j+d]));
            j+=d;
        }
    }
    if(g!=1) ans++;
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
