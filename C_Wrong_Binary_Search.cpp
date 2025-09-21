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
   string s;
   cin>>s;
   bool flag=true;
   int zero=0;
   for(int i=0;i<n;i++) {
    zero+=(s[i]=='0');
    if(s[i]=='1'){
        if(zero==1){
            flag=false;
            break;
        }
        else 
        zero=0;
    }
   }
   if(!flag || zero==1){
    cout<<"NO"<<endl;
    return;
   }
   else{
    cout<<"YES"<<endl;
    vector<int> ans(n);
    iota(begin(ans),end(ans),1);
    for(int i = 0; i < n; ) {
        if(s[i] == '1') {
            i++;
            continue;
        }
        int j = i;
        while(j < n && s[j] == '0') j++;
        reverse(ans.begin() + i, ans.begin() + j);
        i = j;
    }
    for(auto it  : ans) cout<<it<<" ";
    cout<<endl;
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
