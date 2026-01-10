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
   vector<pii> in(n),v(n);
   for(int i=0;i<n;i++)
   {
    int x,y;
    cin>>x>>y;
    in[i]={x,y};
    v[i]={x,y};
   }
   sort(all(v));
   vector<pii> temp;
   for(int i=0;i<n;i++){
    if(i<n-1 && v[i].first==v[i+1].first) continue;
    else temp.pb(v[i]);
   }
   v.clear();
   v=temp;
   if(v.size()==1){
    cout<<-1<<endl;
    return;
   }
   int disjoint=-1,mx=v[0].second;
   for(int i=1;i<v.size();i++){
    if(v[i].first>mx){
        disjoint=v[i].first;
        break;
    }
    mx=max(mx,v[i].second);
   }
   if(disjoint==-1){
    cout<<-1<<endl;
    return;
   }else{
    for(int i=0;i<n;i++){
        if(in[i].first>=disjoint) cout<<2<<" ";
        else cout<<1<<" ";
    }
    cout<<endl;
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
