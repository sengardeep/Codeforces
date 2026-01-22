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
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   map<pii,int> fs,st,ft;
   map<tuple<int,int,int>,int> fst;
   for(int i=0;i<=n-3;i++){
    st[{v[i+1],v[i+2]}]++;
    fs[{v[i],v[i+1]}]++;
    ft[{v[i],v[i+2]}]++;
    fst[{v[i],v[i+1],v[i+2]}]++;
   }
   int ans=0;
   for(int i=0;i<=n-3;i++){
    int f=v[i],s=v[i+1],t=v[i+2];
    int fs1=fs[{f,s}],st1=st[{s,t}],ft1=ft[{f,t}],fst1=fst[{f,s,t}];
    ans+=(fs1+st1+ft1-3*fst1);
    // dbg(f);
    // dbg(s);
    // dbg(t);
    // dbg(fs1);
    // dbg(st1);
    // dbg(ft1);
    // dbg(fst1);
    // cerr<<endl;
    fs[{f,s}]--;
    ft[{f,t}]--;
    st[{s,t}]--;
    fst[{f,s,t}]--;
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
