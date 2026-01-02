#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define MOD_INV(x) mod_exp(x, mod - 2, mod)

int mod_exp(int base, int exp, int mod = mod) {
    int result = 1;
    while (exp) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
const int N = 1e6 + 1;
vector<int> fact(N,1);
vector<int> inv_fact(N,1);
void factorial(){
    for(int i=2;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
void invFactorial(){
    inv_fact[N-1]=MOD_INV(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        inv_fact[i]=(inv_fact[i+1]*(i+1))%mod;
    }
}
int nCr(int n,int r){
    return (((fact[n]*inv_fact[n-r])%mod)*inv_fact[r])%mod;
}


void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   map<int,int> map;
   for(int i=0;i<n;i++){
     cin>>v[i];
     map[v[i]]++;
   }
   int x=v[0];
   for(auto it : v) x&=it;
   if(map.count(x) && map[x]>1){
    int f=map[x];
    int ans=fact[n-2];
    ans=(ans*2LL*nCr(f,2))%mod;
    if(f==n) ans=fact[f];
    cout<<ans<<endl;
   }else{
    cout<<0<<endl;
   }
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   
   factorial();
   invFactorial();
   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
