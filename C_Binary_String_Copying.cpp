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
   int n,q;
   cin>>n>>q;
   string s;
   cin>>s;
   vector<int> st(4*n),lazy(4*n,0);
    auto merge=[](int a,int b){return a+b;};
    function<void(int,int,int)> build=[&](int start,int end,int index)->void{
        if(start==end) {
            st[index]=(s[start]=='0'?0:1);
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,2*index);
        build(mid+1,end,2*index+1);
        st[index]=merge(st[2*index],st[2*index+1]);
    };
    auto propogate=[&](int start,int end,int index){
        if(start==end) {
            lazy[index]=0;
            return;
        }
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
        return;
    };
    function<void(int,int,int,int,int,int)> update=[&](int start,int end,int index,int l,int r,int val)->void{
        if(lazy[index]){
            st[index]=(end-start+1)*lazy[index];
            if(start!=end){
                lazy[2*index]=lazy[index];
                lazy[2*index+1]=lazy[index];
            }
            lazy[index]=0;
        }
        if(l>end||r<start) return;
        if(start>=l&&end<=r){
            lazy[index]=val;
            st[index]=(end-start+1)*lazy[index];
            if(start!=end){
                lazy[2*index]=lazy[index];
                lazy[2*index+1]=lazy[index];
            }
            lazy[index]=0;
            return;
        }
        int mid=(start+end)/2;
        update(start,mid,2*index,l,r,val);
        update(mid+1,end,2*index+1,l,r,val);
        st[index]=merge(st[2*index],st[2*index+1]);
    };
    function<int(int,int,int,int,int)> query=[&](int start,int end,int index,int l,int r)->int{
        if(lazy[index]){
            st[index]=(end-start+1)*lazy[index];
            if(start!=end){
                lazy[2*index]=lazy[index];
                lazy[2*index+1]=lazy[index];
            }
            lazy[index]=0;
        }
        if(l>end||r<start) return 0;
        if(start>=l&&end<=r) return st[index];
        int mid=(start+end)/2;
        int left=query(start,mid,2*index,l,r);
        int right=query(mid+1,end,2*index+1,l,r);
        return merge(left,right);
    };
    build(0,n-1,1);
   vector<int> temp(n,-1);
   int prev=-1;
   for(int i=0;i<n;i++){
      if(s[i]=='0') prev=i;
      else temp[i]=prev;
   }
   int ans=0,flag=1;
   while(q--){
      int l,r;
      cin>>l>>r;
      --l;
      --r;
      if(s[r]=='1') r=temp[r];
      if(r<l)
      {
         if(flag){
            ans++;
            flag=0;
         }else
         continue;
      }
      int sum=query(0,n-1,1,l,r);
      if(sum) {
         ans++;
         update(0,n-1,1,l,r,0);
      }else if(flag){
         ans++;
         flag=0;
      }
   }
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
