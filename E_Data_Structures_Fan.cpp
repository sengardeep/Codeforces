#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>

void solve() {
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   string s;
   cin>>s;
   vector<pii> segTree(4*n);  //{0,1}
   vector<int> lazy(4*n,0);
   auto merge = [&](pii &a,pii &b){
    return make_pair(a.first^b.first,a.second^b.second);
   };
   auto propogate=[&](int start,int end,int index){
    if(start==end){
        lazy[index]=0;
        return;
    }
    lazy[2*index]^=lazy[index];
    lazy[2*index+1]^=lazy[index];
    lazy[index]=0;
   };
   function<void(int,int,int)> build = [&](int start,int end,int index)->void{
    if(start==end){
        if(s[start] == '0') segTree[index]={v[start],0};
        else segTree[index]={0,v[start]};
        return;
    }
    int mid = (start+end)/2;
    build(start,mid,2*index);
    build(mid+1,end,2*index+1);
    segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
   };
   function<void(int,int,int,int,int)> update=[&](int start,int end,int index,int l,int r)->void{
    if(lazy[index] != 0){
        swap(segTree[index].first,segTree[index].second);
        propogate(start,end,index);
    }
    if(l>end || r<start) return;
    if(start>=l && end<=r){
        swap(segTree[index].first,segTree[index].second);
        lazy[index]=1;
        propogate(start,end,index);
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,2*index,l,r);
    update(mid+1,end,2*index+1,l,r);
    segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
   };
   build(0,n-1,1);
   int q;
   cin>>q;
   while(q--){
    int type;
    cin>>type;
    if(type==1){
        int l,r;
        cin>>l>>r;
        update(0,n-1,1,l-1,r-1);
    }
    else{
        int x;
        cin>>x;
        if(x==0) cout<<segTree[1].first<<" ";
        else cout<<segTree[1].second<<" ";
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
