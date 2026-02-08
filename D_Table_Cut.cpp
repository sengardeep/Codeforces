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
   int n,m;
   cin>>n>>m;
   vector<vector<int>> v(n,vector<int>(m));
   for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
   int one=0;
   for(int i=0;i<n;i++) one+=count(all(v[i]),1);
   int req=one/2,sum=0;
   vector<int> temp(n,0);
   for(int i=n-1;i>=0;i--){
    int s=0;
    for(auto it : v[i]) s+=it;
    if(sum+s<=req){
        sum+=s;
        temp[i]=m;
    }
    else{
        int diff=req-sum,curr=0;
        for(int j=0;j<m;j++){
            if(v[i][j]) diff--;
            if(diff<0){
                temp[i]=j;
                break;
            }
        }
        diff=req-sum;
        if(diff==0){
            temp[i]=0;
        }else{
            int count=0;
            for(int j=0;j<m;j++){
                count+=v[i][j];
                if(count==diff){
                    temp[i]=j+1;
                    break;
                }
            }
        }
        sum=req;
        break;
    }
   }
   cout<<(sum*(one-sum))<<endl;
   string ans="";
   int y=0;
   for(int i=0;i<n;i++){
    while(y<temp[i]){
        ans+='R';
        y++;
    }
    ans+='D';
   }
   while(y<m){
    ans+='R';
    y++;
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
