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
   string s;
   cin>>s;
   vector<int> stack;
   vector<int> extra;
   for(int i=0;i<n;i++){
    if(s[i]=='1') stack.push_back(i+1);
    else if(s[i]=='2'){
        if(stack.empty()) continue;
        stack.pop_back();
        extra.pb(i+1);
    }
   }
   for(auto x : extra) stack.pb(x);
   sort(all(stack));
   cout<<stack.size()<<endl;
   for(auto x : stack) cout<<x<<" ";
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
