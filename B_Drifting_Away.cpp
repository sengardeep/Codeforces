#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   string s;
   cin>>s;
   if(s.find("><")!=string::npos || s.find(">*")!=string::npos || s.find("**")!=string::npos || s.find("*<")!=string::npos){
    cout<<-1<<endl;
    return;
   }
   int ans=0;
   //<<<
   for(int i=0;i<s.size();i++){
    if(s[i]=='<' || s[i]=='*') ans++;
    else break;
   }
   int count=0;
   for(int i=s.size()-1;i>=0;i--){
    if(s[i]=='>' || s[i]=='*') count++;
    else break;
   }
   ans=max(ans,count);
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
