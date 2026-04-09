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
   int l=n*(n-1);
   map<int,int> map;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++) 
       {
        int x;
        cin>>x;
        map[x]++;
       }
   }
   for(auto [x,f] : map) {
    if(f>l){
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
