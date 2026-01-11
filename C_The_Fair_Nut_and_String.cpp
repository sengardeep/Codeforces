#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod=1e9+7;

void solve() {
    string s;
    cin>>s;
    int a=0,ans=1;
    for(int i=0;i<s.size();i++){
        a+=(s[i]=='a');
        if(s[i]=='b'){
            ans=(ans*(a+1))%mod;
            a=0;
        }
    }
    ans=(ans*(a+1))%mod;
    cout<<(ans-1+mod)%mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}