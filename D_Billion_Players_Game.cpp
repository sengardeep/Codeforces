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
   int n,l,r;
   cin>>n>>l>>r;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   sort(all(v));
   int i=0,j=n-1;
   vector<char> temp(n,'=');
   while(i<=j){
    if(v[i]<l){
        temp[i]='<';
        i++;
        continue;
    }
    if(v[j]>r){
        temp[j]='>';
        j--;
        continue;
    }
    if(v[i]==v[j]){
        i++;
        j--;
        continue;
    }
    temp[i]='<';
    temp[j]='>';
    i++;
    j--;
   }
   auto calc=[&](int x)->int{
    int ans=0;
    for(int i=0;i<n;i++){
        if(temp[i]=='<'){
            if(x>v[i]) ans+=abs(x-v[i]);
            else ans-=abs(x-v[i]);
        }else if(temp[i]=='>'){
            if(x<v[i]) ans+=abs(x-v[i]);
            else ans-=abs(x-v[i]);
        }
    }
    return ans;
   };
   for(auto it : temp) cerr<<it<<" ";
   int ans=min(calc(l),calc(r));
   cout<<ans<<endl;
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
