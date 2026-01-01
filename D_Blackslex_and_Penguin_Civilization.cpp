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
   if(n==1) {
    cout<<"1 0"<<endl;
    return;
   }
   if(n==2){
    cout<<"3 1 0 2"<<endl;
    return;
   }
   int i=(1LL<<n)-1;
   set<int> set;
   int cnt=1;
   set.insert(i);
   cout<<i<<" ";
   int prev=i;
   while(prev>0)
   {
       int j=prev-cnt;
       int k=j;
       if(j<0) break;
       while(j<prev) {
           cout<<j<<" ";
           j++;
           set.insert(j);
        }
        prev=k;
        cnt=cnt<<1LL;
   }
   for(int j=0;j<prev;j++) {
    if(set.count(j)) continue;
    cout<<j<<" ";
   }
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
