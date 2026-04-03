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
   int s, m;
   cin >> s >> m;
   
   for(int i = 0; i <= 60; i++) {
    if((s & (1LL << i)) && !(m & (1LL << i))){
        cout << -1 << endl;
        return;
    }
    if(m & (1LL << i)){
        break;
    }
   }
   
   vector<int> temp(61);
   for(int i = 60; i >= 0; i--) {
       if(s & (1LL << i)) temp[i] = 1;
   }
   
   auto check = [&](int k){
    vector<int> copy = temp;
    for(int i = 60; i >= 0; i--){
        if(i > 0 && copy[i] && !(m & (1LL << i))){
            int x = copy[i];
            copy[i-1] += 2 * x;
            copy[i] = 0;
        }
        else if(copy[i] > k){
            if(i > 0) { 
                int rem = copy[i] - k;
                copy[i-1] += 2 * rem;
                copy[i] = k;
            }
        }
    }
    for(int i = 0; i <= 60; i++) {
        if(copy[i] > k || (!(m & (1LL << i)) && copy[i] > 0)) return 0;
    }
    return 1;
   };
   
   int start = 1, end = s;
   int ans = end;
   while(start <= end){
    int mid = start + (end - start) / 2; 
    if(check(mid)){
        ans = mid;
        end = mid - 1;
    }
    else {
        start = mid + 1;
    }
   }
   cout << ans << endl;
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
