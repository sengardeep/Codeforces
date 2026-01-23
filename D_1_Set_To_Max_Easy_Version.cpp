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
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   map<int,vector<int>> map;
   for(int i=n-1;i>=0;i--){
    if(i>0 && b[i]!=b[i-1]) map[b[i]].pb(i);
    else if(i==0) map[b[i]].pb(i);
    if(a[i]>b[i]){
        cout<<"NO"<<endl;
        return;
    }
   }
   for(auto [x,v] : map){
    for(auto i : v){
        //left
        int l=i;
        while(l>=0){
            if(a[l]==x) break;
            if(a[l]>x){
                l=-1;
                break;
            }else{
                if(b[l]<x){
                    l=-1;
                    break;
                }
            }
            l--;
        }
        if(l!=-1){
            for(int k=l;k<=i;k++) a[k]=x;
            while(i<n && b[i]==x){
                a[i]=x;
                i++;
            }
            continue;
        }
        //right
        int r=i;
        while(r<n){
            if(a[r]==x) break;
            if(a[r]>x){
                r=-1;
                break;
            }else{
                if(b[r]<x){
                    r=-1;
                    break;
                }
            }
            r++;
        }
        if(r>n-1) r=-1;
        if(r!=-1){
            for(int k=i;k<=r;k++) a[k]=x;
            while(r<n && b[r]==x){
                a[r]=x;
                r++;
            }
            continue;
        }

        if(l==-1 && r==-1) {
            cout<<"NO"<<endl;
            return;
        }
    }
   }
   cout<<"YES"<<endl;
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
