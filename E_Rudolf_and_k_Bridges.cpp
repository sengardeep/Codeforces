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
   int n,m,k,d;
   cin>>n>>m>>k>>d;
   vector<vector<int>> v(n,vector<int>(m));
   for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
   vector<int> cost(n,0);
   for(int i=0;i<n;i++){
    vector<int> temp(m,0);
    multiset<int> ms;
    for(int j=1;j<m;j++){
        if(j<=d+1){
            temp[j]=v[i][j]+1;
            ms.insert(v[i][j]+1);
        }else{
            temp[j]=v[i][j]+1;
            temp[j]+=*ms.begin();
            int idx=j-d-1;
            ms.erase(ms.find(temp[idx]));
            ms.insert(temp[j]);
        }
    }
    cost[i]=temp[m-1]+1;
   }
   int sum=0,ans=0;
   for(int i=0;i<k;i++) sum+=cost[i];
   ans=sum;
   for(int i=k;i<n;i++){
    sum-=cost[i-k];
    sum+=cost[i];
    ans=min(ans,sum);
   }
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
