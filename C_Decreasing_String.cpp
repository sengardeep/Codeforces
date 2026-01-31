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
   string s;
   cin>>s;
   int k;
   cin>>k;
   int i=0,n=s.size();
   while(k>n){
    k-=n;
    n--;
    i++;
   }
   string ans="";
   stack<char> stack;
   for(int j=0;j<s.size();j++){
    while(i>0 && !stack.empty() && stack.top() > s[j]){
        ans.pop_back();
        stack.pop();
        i--;
    }
    ans+=s[j];
    stack.push(s[j]);
   }
   while(i--) ans.pop_back();
   cout<<ans[k-1];
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
