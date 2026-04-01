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
   vector<int> p(n),v(n);
   for(int i=0;i<n;i++) cin>>p[i];
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> map(n+1);
   for(int i=0;i<n;i++) map[p[i]]=i;
   for(int i=0;i<n;i++){
    if(p[i]!=v[i]) {
        int idx = map[v[i]];
        if(idx < i){
            int idx2=map[v[i-1]];
            if(idx2>idx){
                cout<<"NO"<<endl;
                return;
            }
        }else{
            int idx2=map[v[i+1]];
            if(idx2<idx){
                cout<<"NO"<<endl;
                return;
            }
        }
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
