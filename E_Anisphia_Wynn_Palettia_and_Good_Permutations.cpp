#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

vector<int> primes;
vector<int> lp; // least prime factor

void sieve(int N){
    lp.assign(N+1, 0);
    primes.clear();
    for(int i=2;i<=N;i++){
        if(lp[i]==0){
            lp[i]=i;
            primes.pb(i);
        }
        for(int p: primes){
            if(p>lp[i] || i*(int)p > N) break;
            lp[i*p]=p;
        }
    }
}

bool is_prime(int x){
    if(x<2 || x>= (int)lp.size()) return false;
    return lp[x]==x;
}
void solve() {
   int n;
   cin>>n;
   int e=4;
   vector<int> ans;
   set<int> odds;
   for(int i=3;i<=n;i+=2) odds.insert(i);
   ans.pb(1);
   ans.pb(2);
   int count=2;
   int idx=0;
   while(primes[idx]<=n) idx++;
   idx--;
   while(e<=n){
    if(count){
        ans.pb(e);
        e+=2;
    }else{
        if(idx<0){
            if(!odds.empty()){
                int o=*odds.begin();
                odds.erase(odds.begin());
                ans.pb(o);
            }
        }else{
            int num=primes[idx];
            idx--;
            if(odds.count(num)) odds.erase(odds.find(num));
            ans.pb(num);
        }
    }
    count=(count+1)%3;
   }
   while(!odds.empty()) {
    int o=*odds.begin();
    odds.erase(odds.begin());
    ans.pb(o);
   }
   for(auto it : ans) cout<<it<<" ";
   cout<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   sieve(200005);
   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
