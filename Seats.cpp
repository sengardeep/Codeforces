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
   if(n==1){
    cout<<1<<endl;
    return;
   }
   int ans=0,lst=-1;
   for(int i=0;i<n;i++){
    if(s[i]=='1'){
        if(lst==-1) ans+=(i+1)/3;
        else {
            int gap=i-lst-1;
            ans+=gap/3;
        }
        lst=i;
    }
   }
   if(lst==-1) ans+=(n+2)/3;
   else {
    int gap=n-1-lst;
    ans+=(gap+1)/3;
   }
   int one=count(all(s),'1');
   cout<<ans+one<<endl;
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
