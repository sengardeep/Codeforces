#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
int ask(int n){
    cout<<n<<endl;
    int ans; cin>>ans;
    return ans;
}
void solve() {
   int m,n;
   cin>>m>>n;
   //Construct p
   vector<int> p(n);
   for(int i=0;i<n;i++){
    int x = ask(1);
    if(x==0){
        cout<<1<<endl;
        return;
    } 
    if(x==1) p[i]=1;
   }
   int start=1,end=m;
   int i=0,ans=end;
   while(start<=end){
    int mid=(start+end)/2;
    int q=ask(mid);
    if(q==0 && p[i]==1){
        ans=mid;
        break;
    }
    if(p[i]==1){
        if(q==1) start=mid+1;
        else end=mid-1;
    }
    else{
        if(q==1) end=mid-1;
        else start=mid+1;
    }
    i=(i+1)%n;
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
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
