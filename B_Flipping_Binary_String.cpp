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
   int one=count(all(s),'1');
   if(one%2 == 0) {
    cout<<one<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cout<<i+1<<" ";
        }
    }
    if(one)
    cout<<endl;
    return;
   }
   int zero=n-one;
   if(zero%2){
    cout<<zero<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    return;
   }
   cout<<-1<<endl;
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
