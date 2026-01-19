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
   int n,m,k;
   cin>>n>>m>>k;
   vector<int> a(n),b(m);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<m;i++) cin>>b[i];
   string s;
   cin>>s;
   int l=0,r=0;
   map<int,vector<int>> left,right;
   sort(all(b));
   for(int i=0;i<n;i++){
    int ub=upper_bound(all(b),a[i])-begin(b);
    if(ub!=m){
        right[abs(b[ub]-a[i])].push_back(i);
    }
    if(ub!=0) left[abs(b[ub-1]-a[i])].push_back(i);
   }
   int curr=0;
   set<int> ans;
   for(int i=0;i<n;i++) ans.insert(i);
   for(auto c : s){
    if(c=='L'){
        curr--;
        if(curr<l){
            l=curr;
            for(auto x : left[abs(l)]) {
                if(ans.count(x)) ans.erase(x);
            }
        }
    }else{
        curr++;
        if(curr>r){
            r=curr;
            for(auto x : right[r]) {
                if(ans.count(x)) ans.erase(x);
            }
        }
    }
    cout<<ans.size()<<" ";
   }
   cout<<endl;
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
