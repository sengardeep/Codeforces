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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   multiset<int> ms;
   int el=(k + m - 1) / m;
   vector<int> copy=v;
   sort(all(copy));
   for(int i=0;i<el;i++) ms.insert(copy[i]);
   int lst=k%m,extra=0,ans=0;
   for(int i=0;i<n;i++){
    if(ms.count(v[i])){
        if(lst){
            auto it=ms.find(v[i]);
            if(it==prev(ms.end())){
                ans+=(v[i]+extra)*lst;
                extra+=lst;
                lst=0;
            }
            else{
                ans+=(v[i]+extra)*m;
                extra+=m;
            }
        }else{
            ans+=(v[i]+extra)*m;
            extra+=m;
        }
        ms.erase(ms.find(v[i]));
    }
   }
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
