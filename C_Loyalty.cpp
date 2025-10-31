#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n,x;
    cin>>n>>x;
    multiset<int> ms;
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        ms.insert(temp);
    }
    int ans=0,sum=0;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(ms.empty()) break;
        int req=x-sum;
        auto lb=ms.lower_bound(req);
        if(lb==ms.end()) 
        {
            int current = *ms.begin();
            sum+=current;
            res.pb(current);
            ms.erase(ms.begin());
        }
        else{
            auto it = --ms.end(); 
            int val = *it;
            ans+=val;
            res.pb(val);
            sum=(sum+val)%x;
            ms.erase(it);
        }
    }
    cout<<ans<<endl;
    for(auto it : res) cout<<it<<" ";
    cout<<endl;
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
