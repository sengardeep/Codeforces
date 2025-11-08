#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,k;
   cin>>n>>k;
   string s,t;
   cin>>s>>t;
   if(s[0]!=t[0]){
    cout<<-1<<endl;
    return;
   }
   if(s==t){
    cout<<0<<endl;
    return;
   }
   vector<string> temp;
   int ans=-1;
   for(int i=0;i<k;i++){
    for(int i=n-1;i>0;i--){
       if(s[i]!=t[i]){
           s[i]=s[i-1];
        }
        if(s[i]!=t[i] && i-1>0) s[i-1]=s[i-2];
    }
    temp.pb(s);
    if(s==t) {
        ans=i+1;
        break;
    }
   }
   if(s!=t){
    cout<<-1<<endl;
    return;
   }
   cout<<ans<<endl;
   for(auto it : temp) cout<<it<<endl;
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
