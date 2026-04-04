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
   vector<vector<int>> v(n);
   for(int i=0;i<n;i++){
    int k;
    cin>>k;
    vector<int> temp(k);
    set<int> st;
    for(int j=0;j<k;j++) cin>>temp[j];
    reverse(all(temp));
    for(int j=0;j<k;j++){
        if(!st.count(temp[j])){
            st.insert(temp[j]);
            v[i].pb(temp[j]);
        }
    }
   }
   sort(all(v));
   set<int> set;
   for(int i=0;i<n;i++){
    for(int j=0;j<v[i].size();j++) set.insert(v[i][j]);
    for(int j=i+1;j<n;j++){
        vector<int> temp;
        for(int k=0;k<v[j].size();k++){
            if(!set.count(v[j][k])) temp.pb(v[j][k]);
        }
        v[j]=temp;
    }
    sort(begin(v)+i+1,end(v));
   }
   set.clear();
   for(auto it : v)
   {
       for(auto x : it)
       {
           if(!set.count(x))
           {
               set.insert(x);
               cout<<x<<" ";
            }
       }
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
