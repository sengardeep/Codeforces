#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
int ask(vector<int> &v){
    int k=v.size();
    cout<<"? "<<k<<" ";
    for(auto it : v) cout<<it<<" ";
    cout<<endl;
    cout.flush();
    int ans;
    cin>>ans;
    return ans;
}
void solve() {
   int n;
   cin>>n;
   vector<int> v(n+1);
   for(int i=1;i<n+1;i++) cin>>v[i];
   vector<int> pre(n+1,0);
   for(int i=1;i<=n;i++) pre[i]=pre[i-1]+v[i];
   auto query=[&](int l,int r){
    return pre[r]-pre[l-1];
   };
   int start=1,end=n;
   while(start<end){
    int mid = (start+end)/2;
    vector<int> temp; 
    for(int i=start;i<=mid;i++) temp.pb(i);
    int res = ask(temp);
    if(res > query(start,mid)) end=mid;
    else start=mid+1;
   }
   cout<<"! "<<start<<endl;
   cout.flush();
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
