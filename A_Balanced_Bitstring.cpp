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
   int n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   int zero=0,one=0;
   for(int i=0;i<k;i++){
    zero+=(s[i]=='0');
    one+=(s[i]=='1');
   }
   int req=k/2;
   int x=req-zero,y=req-one;
   if(x<0||y<0) {
    cout<<"NO"<<endl;
    return;
   }
   int i=0,j=k;
   while (j<n)
   {
    if(s[i]!='?' && s[i]==s[j]){
        i++;
        j++;
        continue;
    }
    else if(s[i]!='?' && s[j]=='?'){
        s[j]=s[i];
        i++;
        j++;
        continue;   
    }else if(s[i]!='?' && s[j]!=s[i]){
        cout<<"NO"<<endl;
        return;
    }else if(s[i]=='?' && s[i]!=s[j]){
        if(s[j]=='0'){
            x--;
        }else{
            y--;
        }
        if(x<0 || y<0) {
            cout<<"NO"<<endl;
            return;
        }
        i++;
        j++;
    }else{
        i++;
        j++;
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
