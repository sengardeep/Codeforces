#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
int ask(int idx){
    cout<<"? "<<idx<<endl<<flush;
    int ans; cin>>ans;
    return ans;
}
void solve() {
   int n;
   cin>>n;
   int start=1,end=n;
   while(start<=end){
    int mid = (start+end)/2;
    int ai = ask(mid);
    int l=1e10,r=1e10;
    if(mid!=1) l=ask(mid-1);
    if(mid!=n) r=ask(mid+1);
    if(ai<min(l,r)){
        cout<<"! "<<mid<<endl<<flush;
        return;
    }
    if(ai<l && ai>r) start=mid+1;
    if(ai>l && ai<r) end=mid-1;
    if(ai>l && ai>r) end=mid-1;
   }
   return;
}

int32_t main(){
   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
