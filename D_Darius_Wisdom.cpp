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
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   int zero(0),one(0),two(0);
   set<int> set0,set1,set2;
   for(int i=0;i<n;i++){
    if(v[i]==0){
        zero++;
        set0.insert(i);
    }else if(v[i]==1){
        one++;
        set1.insert(i);
    }else{
        two++;
        set2.insert(i);
    }
   }
   vector<pii> ans;
   for(int i=0;i<zero;i++){
    if(v[i]==0) continue;
    if(v[i]==1){
        //Swap with last zero
        int lst=*prev(set0.end());
        set0.erase(prev(set0.end()));
        set1.erase(set1.find(i));
        set1.insert(lst);
        swap(v[i],v[lst]);
        ans.pb({i+1,lst+1});
    }else{
        //Swap with last 1 then swap with last 0
        int lst=*prev(set1.end());
        set1.erase(prev(set1.end()));
        set1.insert(i);
        set2.erase(set2.find(i));
        set2.insert(lst);
        ans.pb({i+1,lst+1});
        swap(v[i],v[lst]);

        lst=*prev(set0.end());
        set0.erase(prev(set0.end()));
        set1.erase(set1.find(i));
        set1.insert(lst);
        swap(v[i],v[lst]);
        ans.pb({i+1,lst+1});
    }
   }
   for(int i=zero;i<zero+one;i++){
    if(v[i]==1) continue;
    int lst=*prev(set1.end());
    set1.erase(prev(set1.end()));
    set1.erase(i);
    set2.insert(lst);
    ans.pb({i+1,lst+1});
    swap(v[i],v[lst]);
   }
   cout<<ans.size()<<endl;
   for(auto [i,j] : ans) cout<<i<<" "<<j<<endl;
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
