#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n, k;
    cin>>n>>k;
    if(k == ((n*n)-1)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int i=0;
    while(i<n){
        for(int j=0; j<n; j++){
            if(k > 0) cout<<"U";
        else{
            if(j==n-1){
                    if(i == n-1) cout<<"L";
                    else cout<<"D";
                }
                else cout<<"RL";
                j++;
            }
            k--;
        }
        i++;
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
