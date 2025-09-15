#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> map;
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
        map[v[i]]++;
    }

    int l=-1,r=-1;
    int diff=0;

    for(int i=0;i<n;i++) 
    {
        if(v[i] && v[i]!=i+1) {
            if(l==-1) l=i;
            r=i;
            diff++;
        }
    }

    int zero=0;
    bool flag=false;
    int f=-1,s=-1;
    for(int i=0;i<n;i++){
        if(v[i]==0){
            zero++;
            if(f==-1) f=i;
            s=i;
        }
    }

    if(zero==0){
        if(diff==0){
            cout<<0<<endl;
        }else{
            cout<<(r-l+1)<<endl;
        }
        return;
    }

    int missingVal = -1;
    if(zero==1){
        for(int x=1;x<=n;x++){
            if(!map.count(x)){
                missingVal = x;
                break;
            }
        }
        if(missingVal == f+1) flag = true;
    }

    if(zero==1){
        if(flag){
            if(diff==0) cout<<0<<endl;
            else cout<<(r-l+1)<<endl;
        }else{
            if(diff==0){
                cout<<1<<endl;
            }else{
                int lo = min(l, f);
                int hi = max(r, f);
                cout<<(hi - lo + 1)<<endl;
            }
        }
        return;
    }

    if(diff==0){
        cout<<(s - f + 1)<<endl;
    }else{
        int lo = min(l, f);
        int hi = max(r, s);
        cout<<(hi - lo + 1)<<endl;
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