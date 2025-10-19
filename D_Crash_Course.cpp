#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count = 0;
    for(int i = 0;i<n;i++){
        if(s[i]=='A')count++;
    }
    if(count==0){
        cout<<"Bob"<<endl;
    }
    else if(count==n || s[n-1]=='A'){
        cout<<"Alice"<<endl;
    }
    else{
        int start = 0, end = n-1;
        int a = 0, b = 0;
        while(start<end){
            if(s[start]==s[start+1]){
                a++;
            }
            if(s[end]==s[end-1]){
                b++;
            }
            start++, end--;
        }
        if(a==b){
            cout<<"Bob"<<endl;
        }
        else cout<<"Alice"<<endl;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}