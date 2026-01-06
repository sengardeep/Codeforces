#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

vector<int> v;
vector<int> dp;
void solve() {
   int n;
   cin>>n;
   cout<<dp[n]<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   auto isPalindrome=[&](int x){
    string s=to_string(x);
    int i=0,j=s.size()-1;
    while(i<=j) {
        if(s[i++]==s[j--]) continue;
        else return 0; 
    }
    return 1;
   };
   const int N=4e4+1;
   for(int i=1;i<=N;i++){
    if(isPalindrome(i)) v.pb(i);
   }
   dp.resize(N+1,0);
   dp[0]=1;
   for(int j=0;j<v.size();j++){
   for(int i=1;i<=N;i++){
        if(i>=v[j]){
            dp[i]=(dp[i]+dp[i-v[j]])%mod;
        }
    }
   }
   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
