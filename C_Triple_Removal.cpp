#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
void solve() {
   int n,q;
   cin>>n>>q;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<int> pre(n,0);
   pre[0]=v[0];
   for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];
   auto rangeSum = [&](int l,int r){
    if(l>0) return pre[r]-pre[l-1];
    else return pre[r];
   };
   vector<int> temp;
   for(int i=0;i<n-1;i++) if(v[i]==v[i+1]) temp.pb(i);
   sort(temp.begin(),temp.end());
   while(q--){
    int l,r;
    cin>>l>>r;
    --r;
    --l;
    int len = r-l+1,sum=rangeSum(l,r);
    if(len%3 || sum%3) cout<<-1<<endl;
    else{
        int ans=len/3;
        int ub=upper_bound(begin(temp),end(temp),(l-1))-temp.begin();
        if(ub<temp.size())
        ub=temp[ub];
        else {
            cout<<ans+1<<endl;
            continue;
        }
        if(ub<r) cout<<ans<<endl;
        else cout<<ans+1<<endl;
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
