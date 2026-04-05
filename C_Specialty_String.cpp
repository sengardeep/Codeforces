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
   int n;
   cin>>n;
   string s;
   cin>>s;
   if(n%2){
    cout<<"NO"<<endl;
    return;
   }
   for(int i=0;i+1<n;i++){
    if(s[i]==s[i+1]){
        int l=i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            s[l]=s[r]='*';
            while(l>=0  && s[l]=='*') l--;
            while(r<n && s[r]=='*') r++;
        }
    }
   }
   for(auto c : s){
    if(c!='*'){
        cout<<"NO"<<endl;
        return;
    }
   }
   cout<<"YES"<<endl;
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
