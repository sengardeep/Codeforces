#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,k,x;
   cin>>n>>k>>x;
   vector<int> v(n);
   map<int,int> map1;
   for(int i=0;i<n;i++) 
   {
       cin>>v[i];
       map1[v[i]]++;
   }
   sort(begin(v),end(v));
   using T=tuple<int,int,int>;
   priority_queue<T> pq;
   pq.push({v[0]-0,0,v[0]});
   for(int i=1;i<n;i++)
   {
    int mid=(v[i]+v[i-1])/2;
    pq.push({mid-v[i-1],v[i-1],mid});
    pq.push({v[i]-mid-1,mid+1,v[i]});
   }
   pq.push({x-v[n-1],v[n-1],x});
   map<int,int> map2;
   vector<int> ans;
   int copy=k;
   while(k--){
    auto [d,x,y]=pq.top(); pq.pop();
    if(map1.count(x)){
        if(map2.count(y)) continue;
        ans.pb(y);
        map2[y]++;
        pq.push({d-1,x,y-1});
    }else{
        if(map2.count(x)) continue;
        ans.pb(x);
        map2[x]++;
        pq.push({d-1,x+1,y});
    }
   }
   if(ans.size()!=copy){
       for(int i=0;i<=x;i++){
           if(map2.count(i)) continue;
           ans.pb(i);
           if(ans.size()==copy) break;
        }
    }
    sort(begin(ans),end(ans));
   for(auto it : ans) cout<<it<<" ";
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