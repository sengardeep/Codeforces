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
   int xr=0;
   vector<int> v(n),pref(n);
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v[i]=x;
    xr^=x;
    pref[i]=xr;
   }
   if(xr==0){cout<<"YES"<<endl;}
   else{
    auto rangeXor=[&](int l,int r)->int{
        int ans=pref[r];
        return (l>0)?ans^pref[l-1]:ans;
    };
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int a=rangeXor(0,i),b=rangeXor(i+1,j),c=rangeXor(j+1,n-1);
            if(a==b && b==c) {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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
