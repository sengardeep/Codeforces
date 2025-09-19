#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// #define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back
int ask(string s){
    cout<<"? "<<s<<endl;
    int ans; cin>>ans;
    return ans;
}
void solve() {
   int n;
   cin>>n;
   //First we will keep trying out with prefix , If at any point our prefix fails then we'll start try out with suffix
   string s="";
   bool flag=true;
   while(s.size()<n){
    if(flag){
        string temp = s+'0';
        int ans = ask(temp);
        if(ans) {
            s=temp;
            continue;
        }
        temp = s + '1';
        ans = ask(temp);
        if(ans){
            s=temp;
            continue;
        }
        flag=false;
    }
    else{
        string temp = '0'+s;
        if(ask(temp)) s=temp;
        else {
            temp='1'+s;
            s=temp;
        }
    }
   }
   cout<<"! "<<s<<endl;
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
