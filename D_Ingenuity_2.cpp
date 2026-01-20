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
   map<char,int> map1,map2;
   map1['N']=map2['N']=0;
   map1['E']=map2['E']=0;
   map1['W']=map2['W']=0;
   map1['S']=map2['S']=0;
   string ans="";
   int flag1=0,flag2=0;
   for(auto c : s){
    if(c=='N' || c=='S'){
        if(map1[c]==map2[c]){
            ans+='R';
            flag1=1;
            map1[c]++;
        }else {
            ans+='H';
            flag2=1;
            map2[c]++;
        }
    }else{
        if(map2[c]==map1[c]){
            ans+='H';
            flag2=1;
            map2[c]++;
        }else {
            ans+='R';
            flag1=1;
            map1[c]++;
        }
    }
   }
   int diff1=map1['N']-map1['S'],diff2=map2['N']-map2['S'];
   int diff3=map1['E']-map1['W'],diff4=map2['E']-map2['W'];
   if((diff1==diff2 && diff3==diff4)&&(flag1 && flag2)) cout<<ans<<endl;
   else cout<<"NO"<<endl;
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
