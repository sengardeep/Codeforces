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
   map<int,int> map;
   for(int i=0;i<n;i++) map[v[i]]=i;
   int j=0;
   for(int i=n;i>=1;i--){
    if(map[i]!=j){
        reverse(begin(v)+j,begin(v)+map[i]+1);
        break;
    }else j++;
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
