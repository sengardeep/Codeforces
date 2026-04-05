#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void rotate(vector<int> &v,int k){
    int n=v.size();
    if(n==0) return;
    k%=n;
    if(k<0) k+=n;
    reverse(v.begin(), v.begin()+k);
    reverse(v.begin()+k, v.end());
    reverse(v.begin(), v.end());
}

void solve() {
   int n,x,y;
   cin>>n>>x>>y;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> a,b;
   for(int i=0;i<x;i++) a.pb(v[i]);
   for(int i=y;i<n;i++) a.pb(v[i]);
   for(int i=x;i<y;i++) b.pb(v[i]);

   if(!b.empty()){
    int mn=min_element(all(b))-begin(b);
    rotate(b,mn);
   }

   int i=0,j=0;
   while(i<a.size()){
    if(j<b.size() && a[i]>b[j]) break;
    cout<<a[i++]<<" ";
   }
   while(j<b.size()) cout<<b[j++]<<" ";
   while(i<a.size()) cout<<a[i++]<<" ";
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
