#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,x,y;
   cin>>n>>x>>y;
   string s;
   cin>>s;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int zero=0;
   for(auto it : s) zero+=it=='0';
   if((zero==n && x<=y)||(zero==0 && x>=y)){
    cout<<"NO"<<endl;
    return;
   } 
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++){
    if(s[i]=='0'){
        a[i]=v[i];
        x-=v[i];
    }else{
        b[i]=v[i];
        y-=v[i];
    }
   }
   if(x<0){
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            a[i]=(v[i]/2)+1;
            b[i]=v[i]-a[i];
            x+=b[i];
        }
    }
   }else if(y>0){
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            b[i]=(v[i]/2)+1;
            a[i]=v[i]-b[i];
            y+=b[i];
        }
    }
   }
   if(x>=0 && y>=0){
    cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
   }
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
