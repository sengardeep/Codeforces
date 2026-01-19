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
   vector<int> v(n+1);
   for(int i=1;i<n+1;i++) cin>>v[i];
   vector<pii> in(n+1);
   for(int i=1;i<n+1;i++) cin>>in[i].first>>in[i].second;
   vector<pii> range(n+1);
   range[0]={0,0};
   for(int i=1;i<=n;i++) {
    auto &[l,r]=range[i-1];
    int mn=0,mx=0;
    if(v[i]==0) {
        mn=l;
        mx=r;
    }
    if(v[i]==1) {
        mn=l+1;
        mx=r+1;
    }
    if(v[i]==-1){
        mn=l;
        mx=r+1;
    }
    range[i]={max(mn,in[i].first),min(mx,in[i].second)};
    if(range[i].first > range[i].second){
        cout<<-1<<endl;
        return;
    }
   }
   int h=range[n].first;
   for(int i=n;i>0;i--){
    if(v[i]==1) h--;
    else if(v[i]==0) continue;
    else{
        int l=range[i-1].first,r=range[i-1].second;
        if(h>=l && h<=r) v[i]=0;
        else 
        {
            v[i]=1;
            h--;
        }
    }
   }
   for(int i=1;i<=n;i++) cout<<v[i]<<" ";
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
