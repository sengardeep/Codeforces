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
   if(n%2){
    cout<<n<<endl;
    v[n-1]=n;
    v[n-2]=n-1;
    set<int> set;
    set.insert(n);
    set.insert(n-1);
    int l=__lg(n);
    int x=(1<<(l-1));
    set.insert(x);
    v[n-2]=x;
    int j=0;
    for(int i=1;i<=n;i++){
        if(set.count(i)) continue;
        v[j++]=i;
    }
    for(auto x : v) cout<<x<<" ";
    cout<<endl;
   }else{
    int l=__lg(n);
    cout<<((1<<l)-1)<<endl;
    v[n-1]=n;
    int x=(1<<(l-1));
    v[n-2]=x;
    v[n-3]=x-1;
    v[n-4]=3;
    v[n-5]=1;
    set<int> set;
    set.insert(1);
    set.insert(3);
    set.insert(x);
    set.insert(x-1);
    set.insert(n);
    int j=0;
    for(int i=1;i<=n;i++){
        if(set.count(i)) continue;
        v[j++]=i;
    }
    for(auto x : v) cout<<x<<" ";
    cout<<endl;
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
