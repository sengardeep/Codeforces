#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

//We'll be using weighted DSU here 
void solve() {
   int n,q;
   cin>>n>>q;
   vector<pii> parent(n+1);
   vector<int> rank(n+1,0);
   for(int i=1;i<=n;i++) parent[i]={i,0};
   while(q--){
    int type,a,b;
    cin>>type>>a>>b;
    if(type==1)
    {

    }
    else{

    }
   }
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
