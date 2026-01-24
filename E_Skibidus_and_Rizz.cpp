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
   int n,m,k;
   cin>>n>>m>>k;
   if((abs(n-m)>k)||(n<k && m<k)){
    cout<<-1<<endl;
    return;
   }
   if(n>m){
    for(int i=0;i<k;i++) cout<<"0";
    n-=k;
    int rem=n+m;
    for(int i=0;i<rem;i++){
        if(m-->0) cout<<"1";
        if(n-->0) cout<<"0";
    }
    cout<<endl;
   }else{
    for(int i=0;i<k;i++) cout<<"1";
    m-=k;
    int rem=n+m;
    for(int i=0;i<rem;i++){
        if(n-->0) cout<<"0";
        if(m-->0) cout<<"1";
    }
    cout<<endl;
   }
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
