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
   int a,b;
   cin>>a>>b;
   if((a&b)==0){
    cout<<a<<" "<<b<<endl;
    return;
   }
   int k=0;
   for(int i=0;i<=31;i++){
    if(a&(1<<i) && b&(1<<i)){
        k=i;
    }
   }
   int p=-1,q=-1,diff=-1;
   int x=a,y=b;
   if(x&(1<<k)) x^=(1<<k);
   for(int i=k-1;i>=0;i--){
    if(!(y&(1<<i))){
        if(!(x&(1<<i))) x|=(1<<i);
    }else{
        if(x&(1<<i)) x^=(1<<i);
    }
   }
   diff=abs(x-a)+abs(y-b);
   p=x;
   q=y;

   x=a;
   y=b;
   if(y&(1<<k)) y^=(1<<k);
   for(int i=k-1;i>=0;i--){
    if(!(x&(1<<i))){
        if(!(y&(1<<i))) y|=(1<<i);
    }else{
        if(y&(1<<i)) y^=(1<<i);
    }
   }
   int diff2=abs(x-a)+abs(y-b);
   if(diff2<diff){
    diff=diff2;
    p=x;
    q=y;
   }

   for(int i=k+1;i<=30;i++){
    if(!(a&(1<<i)) && !(b&(1<<i))){
        x=a,y=b;
        x|=(1<<i);
        for(int j=0;j<i;j++){
            if(x&(1<<j)) x^=(1<<j);
        }
        diff2=abs(x-a)+abs(y-b);
        if(diff2<diff){
            diff=diff2;
            p=x;
            q=y;
        }
        x=a,y=b;
        y|=(1<<i);
        for(int j=0;j<i;j++){
            if(y&(1<<j)) y^=(1<<j);
        }
        diff2=abs(x-a)+abs(y-b);
        if(diff2<diff){
            diff=diff2;
            p=x;
            q=y;
        }
        break;
    }
   }
   cout<<p<<" "<<q<<endl;
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
