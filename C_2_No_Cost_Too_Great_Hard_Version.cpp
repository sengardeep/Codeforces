#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

vector<int> primeFactors(int x) {
    if(x==1) return {};
    vector<int> res;
    if ((x & 1LL) == 0) {
        res.pb(2);
        while ((x & 1LL) == 0) x >>= 1;
    }
    for (int p = 3; p <= x / p; p += 2) {
        if (x % p == 0) {
            res.pb(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) res.pb(x);
    return res;
}
void solve() {
   int n;
   cin>>n;
   vector<int> v(n),b(n);
   for(int i=0;i<n;i++) cin>>v[i];
   for(int i=0;i<n;i++) cin>>b[i];
   map<int,int> map;
   for(int i=0;i<n;i++){
    vector<int> temp=primeFactors(v[i]);
    for(auto it : temp) 
    {
        map[it]++;
        if(map[it]>1){
            cout<<0<<endl;
            return;
        }
    }
   }
   int ans=1e9;
   for(int i=0;i<n;i++){
    vector<int> temp1=primeFactors(v[i]);
    for(auto it : temp1) map[it]--;
    vector<int> temp2=primeFactors(v[i]+1);
    for(auto it : temp2) 
    {
        map[it]++;
        if(map[it]>1){
            ans=min(ans,b[i]);
            break;
        }
    }
    for(auto it : temp2) map[it]--;
    for(auto it : temp1) map[it]++;
   }
   int idx1=-1,idx2=-1;
   int mn=1e9;
   for(int i=0;i<n;i++){
    if(b[i]<mn){
        mn=b[i];
        idx1=i;
    }
   }
   mn=1e9;
   for(int i=0;i<n;i++){
    if(i==idx1) continue;
    if(b[i]<mn){
        mn=b[i];
        idx2=i;
    }
   }
   if(v[idx1]%2==0) ans=min(ans,b[idx2]);
   else if(v[idx2]%2==0) ans=min(ans,b[idx1]);
   else ans=min(ans,b[idx1]+b[idx2]);
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
