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
   int n,k;
   cin>>n>>k;
   vector<int> v(n,0);
   for(int i=0;i<k;i++){
    string s;
    cin>>s;
    for(int j=0;j<n;j++)
    {
        int p=s[j]-'a';
        v[j]|=(1<<p);
    }
   }
   vector<int> divisors;
   for(int i=1; i*i<=n; i++){
       if(n%i==0){
           divisors.pb(i);
           if(i != n/i) divisors.pb(n/i);
       }
   }
   sort(all(divisors));
   for(int i=0;i<divisors.size();i++){
    int len=divisors[i],flag=1;
    string temp="";
    for(int p=0;p<len;p++){
        int mask=(1<<27)-1;
        for(int j=p;j<n;j+=len) mask &= v[j];
        if(mask==0) {
            flag=0;
            break;
        }
        else{
            char c='a'+__builtin_ctz(mask);
            temp+=c;
        }
    }
    if(flag){
        string ans=temp;
        while(ans.size()<n) ans+=temp;
        cout<<ans<<endl;
        return;
    }
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
