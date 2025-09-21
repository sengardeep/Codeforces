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
   if(n==1){
    cout<<"1 1"<<endl;
    return;
   }
   if(n==2){
    cout<<"1 2 1 2"<<endl;
    return;
   }
   if(n==3){
    cout<<"1 3 1 2 3 2"<<endl;
    return;
   }
   vector<int> ans(2*n,-1);
   ans[0]=ans[n]=n;
   ans[1]=ans[n-1]=n-2;
   ans[2]=ans[n+1]=n-1;
   int x=n-3,i=3;
   while(x>=1){
    while(ans[i]!=-1) i++;
    ans[i]=x;
    int m=1;
    while(ans[i+m*x]!=-1) m++;
    ans[i+m*x]=x;
    x--;
   }
   for(auto it : ans) cout<<it<<" ";
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
