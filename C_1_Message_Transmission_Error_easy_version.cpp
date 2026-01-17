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
    int n=s.size();
    if(n<3) {
        cout<<"NO";
        return;
    }
    int curr=n/2+1;
    while(curr<=n-1){
        string s1=s.substr(0,curr);
        int idx=n-curr;
        string s2=s.substr(idx);
        if(s1==s2){
            cout<<"YES"<<endl;
            cout<<s1;
            return;
        }
        curr++;
    }
    cout<<"NO";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}