#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
int ask(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int ans; cin>>ans;
    return ans;
}
void solve() {
   int n,t,k;
   cin>>n>>t>>k;
   int start=1,end=n;
   while(start<=end){
    int mid=(start+end)/2;
    int left=ask(start,mid);
    int s=(mid-start+1)-left;
    if(s>=k) end=mid-1;
    else 
    {
        k-=s;
        start=mid+1;
    }
   }
   cout<<"! "<<start<<endl;

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
