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
   int n,h,k;
   cin>>n>>h>>k;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int sum = 0;
   for(auto x : v) sum+=x;
   int d=(h-1)/sum;
   int time=d*(n+k);
   h-=(d*sum);
   vector<int> mx(n+1,0);
   for(int i=n-1;i>=0;i--) mx[i]=max(v[i],mx[i+1]);
   int mn=1e10,y=0;
   for(int i=0;i<n;i++){
    mn=min(mn,v[i]);
    y+=v[i];
    int damage=y;
    if(i+1<n && mx[i+1]>mn){
        damage += (mx[i+1]-mn);
    }
    if(damage>=h){
        cout<<time+i+1<<endl;
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
