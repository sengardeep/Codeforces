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
   vector<int> v;
   map<int,int> map;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    map[x]++;
   }
   for(auto [el,f] : map) v.pb(el);
   n=v.size();
   for(int i=0;i<n;i++){
    int num=v[i];
    if(map[num]>=4){
        cout<<"Yes"<<endl;
        return;
    }
    if(map[num]>=2){
        int idx=i+1,x=num+1;
        while(idx<n && v[idx]==x) {
            if(map[v[idx]]>=2){
                cout<<"Yes"<<endl;
                return;
            }
            x++;
            idx++;
        }
        idx--;
        i=idx;
    }
   }
   cout<<"No"<<endl;
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
