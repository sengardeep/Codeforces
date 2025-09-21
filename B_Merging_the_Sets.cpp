#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n,m;
    cin>>n>>m;
    vector<map<int,int>> v(n);
    map<int,int> map;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        for(int j=0;j<s;j++){
            int x;
            cin>>x;
            map[x]++;
            v[i][x]++;
        }
    }
    int ans=0;
    vector<int> indices;
    for(int i=0;i<n;i++){
        bool flag=true;
        for(auto [num,f] : v[i]){
            if(map[num] == 1) 
            {
                flag=false;
                break;
            }
        }
        if(flag) indices.pb(i);
        ans += (flag);
    }
    if(ans >= 2 && map.size()==m) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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
