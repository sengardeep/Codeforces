#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back


string ask(int x){
    cout<<x<<endl;
    string s; cin>>s;
    return s;
}
void solve() {
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int cnt=0;
    for(int i=0;i<primes.size();i++){
        if(ask(primes[i])=="yes") 
        {
            cnt++;
            if(primes[i]<10)
            if(ask(primes[i]*primes[i])=="yes") cnt++;
        }
        if(cnt>1) {
            cout<<"composite";
            return;
        }
    }
    cout<<"prime";
}

int32_t main(){
   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
