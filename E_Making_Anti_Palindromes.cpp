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
   if(n%2){
    cout<<-1<<endl;
    return;
   }
   vector<int> map(26,0);
   for(auto c : s) {
    map[c-'a']++;
    if(map[c-'a'] > n/2){
        cout<<-1<<endl;
        return;
    }
   }
   map.clear();
   map.resize(26,0);
   for(int i=0;i<n/2;i++){
    if(s[i]==s[n-i-1]) map[s[i]-'a']++;
   }
   int ans=0,mx=0,sum=0;
   for(auto x : map){
    sum+=x;
    mx=max(mx,x);
   }
   ans=max(mx,(sum+1)/2);
   cout<<ans<<endl;
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
