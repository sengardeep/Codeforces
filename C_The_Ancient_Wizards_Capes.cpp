#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=676767677;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    auto helper=[&](int k){
        vector<int> c(n);
        c[0]=k;
        for(int i=0;i<n-1;i++){
            int d=v[i+1]-v[i];
            c[i+1]=1-d-c[i];
            if(c[i+1]!=0 && c[i+1]!=1) return 0;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if((c[i]==0 && i==0)||(c[i]==1 && i>=0)) cnt++;
        }
        return (cnt==v[0])?1:0;
    };
    int ans=helper(0)+helper(1);
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
