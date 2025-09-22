#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int q;
   cin>>q;
   bool flag=false;
   multiset<int> ms1,ms2;
   while(q--){
    char sign;
    cin>>sign;
    if(sign=='+'){
        int l,r;
        cin>>l>>r;
        ms1.insert(l);
        ms2.insert(r);
        int x = *ms2.begin();
        auto it = ms1.upper_bound(x);
        if(it!=ms1.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
        int l,r;
        cin>>l>>r;
        ms1.erase(ms1.find(l));
        ms2.erase(ms2.find(r));
        int x = *ms2.begin();
        auto it = ms1.upper_bound(x);
        if(it!=ms1.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
