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
   vector<int> a(n),b(n),c(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   for(int i=0;i<n;i++) cin>>c[i];
   vector<int> pre1(n,0),pre2(n,0),pre3(n,0);
   pre1[0]=a[0];
   pre2[0]=b[0];
   pre3[0]=c[0];
   for(int i=1;i<n;i++) pre1[i]=pre1[i-1]+a[i];
   for(int i=1;i<n;i++) pre2[i]=pre2[i-1]+b[i];
   for(int i=1;i<n;i++) pre3[i]=pre3[i-1]+c[i];
   int req=pre1[n-1]/3;
   if(pre1[n-1]%3) req++;
   int la=-1,ra=-1,lb=-1,rb=-1,lc=-1,rc=-1;
   function<int(int,int)> helper=[&](int flag,int index)->int{
    if(flag==7) return 1;
    if(index>=n) return 0; 
    if(!(flag&(1<<0))){
        int nxt=lower_bound(begin(pre1)+index,end(pre1),req+((index>0)?pre1[index-1]:0))-begin(pre1);
        if(nxt!=n) {
            la=index;
            ra=nxt;
            int ans=helper(flag|(1<<0),nxt+1);
            if(ans) return ans;
        } 
    }
    if(!(flag&(1<<1))){
        int nxt=lower_bound(begin(pre2)+index,end(pre2),req+((index>0)?pre2[index-1]:0))-begin(pre2);
        if(nxt!=n) {
            lb=index;
            rb=nxt;
            int ans=helper(flag|(1<<1),nxt+1);
            if(ans) return ans;
        } 
    }
    if(!(flag&(1<<2))){
        int nxt=lower_bound(begin(pre3)+index,end(pre3),req+((index>0)?pre3[index-1]:0))-begin(pre3);
        if(nxt!=n) {
            lc=index;
            rc=nxt;
            int ans=helper(flag|(1<<2),nxt+1);
            if(ans) return ans;
        } 
    }
    return 0;
   };
   if(helper(0,0)){
    if(ra>rb && ra>rc) ra=max(ra,n-1);
    if(rb>ra && rb>rc) rb=max(rb,n-1);
    if(rc>rb && rc>ra) rc=max(rc,n-1);
    cout<<la+1<<" "<<ra+1<<" "<<lb+1<<" "<<rb+1<<" "<<lc+1<<" "<<rc+1<<endl;
   }else cout<<-1<<endl;
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
