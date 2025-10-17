#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin>>n;
    auto ask=[&](int l,int r,int i){
        cout<<i<<" "<<l<<" "<<r<<endl;
        int ans; cin>>ans;
        return ans;
    };
    int len=ask(1,n,2);
    int sum=n*(n+1)/2;
    len = len-sum; 
    int start=1,end=n;
    while(start<end){
        int mid=(start+end)/2;
        int diff = ask(1, mid, 2) - ask(1, mid, 1);
        if(diff==len){
            end=mid;
        }else{
            start=mid+1;
        }
    }
    cout<<"! "<<(start - len + 1)<<" "<<start<<endl;
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
