#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
vector<int> ask(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    vector<int> ans(r-l+1);
    for(int i=0;i<(r-l+1);i++) cin>>ans[i];
    return ans;
}
bool check(vector<int>&a,int l,int r){
    int ans=0;
    for(auto it:a) ans += (it>=l && it<=r);
    return ans%2;
}
void solve() {
    int n;
    cin>>n;
    // count the number of ai such that l≤ai≤r We claim that if this count is odd, then the subarray contains the fixed point; otherwise, it does not.
    int start=1,end=n;
    while(start<end){
        int mid=(start+end)/2;
        vector<int> nums = ask(start,mid);
        if(check(nums,start,mid)) end=mid;
        else start=mid+1;
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
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
