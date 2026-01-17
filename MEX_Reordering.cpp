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
   sort(all(v));
   auto mex=[&](int l,int r){
    set<int> set;
    int x=0;
    for(int i=l;i<=r;i++) set.insert(v[i]);
    while(set.count(x)) x++;
    return x;
   };
   for(int i=0;i<n-1;i++){
    int m1=mex(0,i);
    int m2=mex(i+1,n-1);
    if(m1==m2){
        cout<<"NO"<<endl;
        return;
    }
   }
   cout<<"YES"<<endl;
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
