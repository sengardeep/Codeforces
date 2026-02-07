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
   int n,s1,s2;
   cin>>n>>s1>>s2;
   priority_queue<pii> pq;
   for(int i=0;i<n;i++){
    int f;
    cin>>f;
    pq.push({f,i+1});
   }
   int x=s1,y=s2;
   vector<int> a,b;
   while(!pq.empty()){
    auto [f,num]=pq.top(); pq.pop();
    int temp1=x*f,temp2=y*f;
    if(temp1>temp2){
        b.pb(num);
        y+=s2;
    }else{
        a.pb(num);
        x+=s1;
    }
   }
   cout<<a.size()<<" ";
   for(auto x : a) cout<<x<<" ";
   cout<<endl;
   cout<<b.size()<<" ";
   for(auto x : b) cout<<x<<" ";
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
