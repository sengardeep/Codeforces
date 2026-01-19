#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

int mod_exp(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
void solve() {
   int l,r,k;
   cin>>l>>r>>k;
   if(k>=10) {
    cout<<0<<endl;
    return;
   }
   auto f=[&](int x){
    int cnt=0;
    for(int i=1;i<=9;i++) {
        if(i*k < 10) cnt++;
        else break;
    }
    int n=x;
    int a=1;
    int r=cnt+1;
    int p=mod_exp(r,n);
    int num=(a*1LL*((p-1+mod)%mod))%mod;
    int den=(r-1+mod)%mod;
    int sum=(num*1LL*mod_exp(den,mod-2))%mod;
    int ans=(cnt*1LL*sum)%mod;
    if(x==1) ans=cnt;
    if(x==0) ans=0;
    return ans;
   };
   int left=f(l);
   int right=f(r);
   int ans=(right-left+mod)%mod;
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
