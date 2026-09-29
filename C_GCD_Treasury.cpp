#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

int N=3e5+5;
vector<vector<int>> pf(N+1);
void precompute(){
    for(int i=2;i<=N;i++){
     if(pf[i].empty()){
        for(int j=i;j<=N;j+=i) pf[j].push_back(i);
     }
    }
}

void solve() {
   int n,k;
   cin>>n>>k;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> factors = pf[k];
   int ans=0;
   for(int x : factors){
    int res=0;
    for(int i : v){
        if(i%x==0){
            res+=i;
        }
    }
    ans=max(ans,res);
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
   precompute();
   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
