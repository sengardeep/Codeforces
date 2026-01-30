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
   int n,x;
   cin>>n>>x;
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];

   priority_queue<pii> pq;
   for(int i=0;i<n;i++) pq.push({a[i],i});

   sort(all(b));
   vector<int> ans(n);
   for(int i=x-1;i>=0;i--){
    auto [num,idx] = pq.top();
    pq.pop();
    if(b[i]<num) ans[idx]=b[i];
    else {
        cout<<"NO"<<endl;
        return;
    }
   }
   for(int i=n-1;i>=x;i--){
    auto [num,idx] = pq.top();
    pq.pop();
    if(b[i]>=num) ans[idx]=b[i];
    else {
        cout<<"NO"<<endl;
        return;
    }
   }
   cout<<"YES"<<endl;
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
