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
   int pos=-1;
   for(int i=0;i<n;i++) if(v[i]!=1 && v[i]!=-1) pos=i;
   auto find=[&](int l,int r){
    int mn=0,mx=0;
    int currMn=0,currMx=0;
    for(int i=l;i<=r;i++){
        currMx=max(0LL,currMx+v[i]);
        mx=max(mx,currMx);
        currMn=min(0LL,currMn+v[i]);
        mn=min(mn,currMn);
    }
    return make_pair(mn,mx);
   };
   if(pos==-1){
    auto [l,r]=find(0,n-1);
    set<int> ans;
    for(int i=l;i<=r;i++) ans.insert(i);
    ans.insert(0);
    cout<<ans.size()<<endl;
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
   }else{
    set<int> ans;
    int mnS=0,mxS=0;
    if(pos>0){
        auto left=find(0,pos-1);
        for(int i=left.first;i<=left.second;i++) ans.insert(i);
        int s=0;
        for(int i=pos-1;i>=0;i--){
            s+=v[i];
            mnS=min(mnS,s);
            mxS=max(mxS,s);
        }
    }
    int mnP=0,mxP=0;
    if(pos<n-1){
        auto right=find(pos+1,n-1);
        for(int i=right.first;i<=right.second;i++) ans.insert(i);
        int s=0;
        for(int i=pos+1;i<n;i++){
            s+=v[i];
            mnP=min(mnP,s);
            mxP=max(mxP,s);
        }
    }
    int l=mnS+mnP+v[pos],r=mxS+mxP+v[pos];
    for(int i=l;i<=r;i++) ans.insert(i);
    ans.insert(0);
    cout<<ans.size()<<endl;
    for(auto x : ans) cout<<x<<" ";
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
