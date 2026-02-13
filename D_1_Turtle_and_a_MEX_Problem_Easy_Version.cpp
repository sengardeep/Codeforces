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
   int n,m;
   cin>>n>>m;
   int mx=0;
   for(int i=0;i<n;i++){
    int k;
    cin>>k;
    set<int> set;
    for(int j=0;j<k;j++){
        int x;
        cin>>x;
        set.insert(x);
    }
    int num=0,flag=1;
    while(true){
        if(set.count(num)) num++;
        else {
            if(flag) 
            {
                num++;
                flag=0;
            }
            else break;
        }
    }
    mx=max(mx,num);
   }
   int ans=(m*(m+1)/2)+(mx*(mx+1)/2);
   if(mx>=m) ans=mx*(m+1);
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
