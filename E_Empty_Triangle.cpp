#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()

void solve() {
   int n;
   cin>>n;
   auto randInt = [](int l, int r) {
       static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
       return uniform_int_distribution<int>(l, r)(rng);
   };
   vector<int> vec{1,2,3};
   for(int i=0;i<75;i++){
    cout<<"? "<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;
    int ans; cin>>ans;
    if(ans==0){
        cout<<"! "<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;
        return;
    }else{
        int idx=randInt(0,2);
        vec[idx]=ans;
    }
   }
   cout<<-1<<endl;
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
