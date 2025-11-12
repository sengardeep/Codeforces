#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> map;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        map[v[i]]=i;
    }
    string x;
    cin>>x;
    int f=map[1], l=map[n];
    if (x[0]=='1' || x[n-1]=='1' || x[f]=='1' || x[l]=='1') {
        cout<<-1<<endl;
        return;
    }
    int L=min(f,l)+1,R=max(f,l)+1;
    cout<<5<<endl;
    cout<<L<<" "<<R<<endl;
    cout<<1<<" "<<L<<endl;
    cout<<1<<" "<<R<<endl;
    cout<<L<<" "<<n<<endl;
    cout<<R<<" "<<n<<endl;
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
