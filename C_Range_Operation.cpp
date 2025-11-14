#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+v[i];
    int sum=pre[n];
    int add=0,mn=1e9;
    for(int i=1;i<=n;i++){
        int sub=i*i-i-pre[i-1];
        if(sub<mn) mn=sub;
        int x=i*i+i-pre[i];
        add=max(add,x-mn);
    }
    cout<<sum+add<<endl;
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
