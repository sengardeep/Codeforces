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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int flag=1;
   for(int i=0;i+1<n;i++){
    if(v[i]>v[i+1]){
        flag=0;
        break;
    }
   }
   if(flag){
    cout<<"Bob"<<endl;
    return;
   }
   auto helper=[&](int x){
    int count=0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            count++;
            while(x%i==0) x/=i;
        }
        if(count>1) return true;
    }
    if(x>1) count++;
    return (count>1);
   };
   for(int i=0;i<n;i++) {
    if(helper(v[i])){
        cout<<"Alice"<<endl;
        return;
    }
   }
    auto spf = [&](int x) -> int {
        if (x <= 1) return x;
        for (int p = 2; p * p <= x; ++p) {
        if (x % p == 0) return p;
        }
        return x; // x is prime
    };
    for(int i=0;i<n;i++) v[i]=spf(v[i]);
    for(int i=0;i+1<n;i++) {
        if(v[i]>v[i+1]) {
            cout<<"Alice"<<endl;
            return;
        }
    }
    cout<<"Bob"<<endl;
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
