#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(x) begin(x),end(x)

void solve() {
   int n;
   cin>>n;
   vector<pii> v(n);
   for(int i=0;i<n;i++) cin>>v[i].first;
   for(int i=0;i<n;i++) cin>>v[i].second;
   sort(all(v));
   vector<vector<int>> a;
   int curr=v[0].first;
   vector<int> temp;
   for(int i=0;i<n;i++){
    if(curr==v[i].first){
        temp.pb(v[i].second);
    }else{
        // sort(all(temp));
        reverse(all(temp));
        a.pb(temp);
        temp.clear();
        curr=v[i].first;
        temp.pb(v[i].second);
    }
   }
   if(!temp.empty()){
    reverse(all(temp));
    a.pb(temp);
   }
   for(auto &it : a){
    for(int i=1;i<it.size();i++) it[i]+=it[i-1];
   }
   sort(all(a),[&](vector<int>&x,vector<int>&y){
    return x.size()>y.size();
   });
   for(int k=1;k<=n;k++){
    if(k>a[0].size()){
        cout<<0<<" ";
        continue;
    }
    int ans=0;
    for(int i=0;i<a.size();i++){
        int s=a[i].size();
        if(k>s) break;
        int x=s%k;
        ans+=a[i][s-x-1];
    }
    cout<<ans<<" ";
   }
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
