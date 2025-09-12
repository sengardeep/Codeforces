#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

int ask(int a,int b){
    cout<<"?"<<" "<<a<<" "<<b<<endl;
    int ans; cin>>ans;
    return ans;
}
void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   map<int,int> map;
   for(int i=0;i<n;i++) 
   {
       cin>>v[i];
       map[v[i]]=i+1;
   }
   int num=-1;
   for(int i=1;i<=n;i++) if(map.count(i)==0) num=i;

   if(num!=-1)
   {
       if(ask(num,v[0]) == 0){
        cout<<"! A"<<endl;
        return;
       }
       else{
        cout<<"! B"<<endl;
        return;
       }
   }
   for(int i=0;i<n;i++) map[v[i]]=i+1;
   int a = ask(map[1],map[n]);
   int b = ask(map[n],map[1]);
   if(a==b && a>=n-1){
    cout<<"! B"<<endl;
   }
   else{
    cout<<"! A"<<endl;
   }
}

int32_t main(){
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
