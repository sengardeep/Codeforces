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
   int i=n-1,j=n-2;
   priority_queue<int,vector<int>,greater<int>> pq;
   multiset<int> ms;
   for(auto x : v) ms.insert(x);
   vector<int> ans;
   for(int x : v){
    if(*ms.begin()==x) ans.pb(x);
    else pq.push(x+1);
    ms.erase(ms.find(x));
   }
   while(!ans.empty() && !pq.empty() && ans.back()>pq.top()){
    pq.push(ans.back()+1);
    ans.pop_back();
   }
   while(!pq.empty()){
    int top=pq.top();
    pq.pop();
    ans.pb(top);
   }
   for(auto x : ans) cout<<x<<" ";
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
