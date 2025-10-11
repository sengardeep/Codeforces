#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl;
#define pii pair<int,int>

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    map<int,vector<int>> map;
    for(int i=0;i<n;i++) map[a[i]].push_back(i);
    for(int i=0;i<n;i++) 
    {
        if(map.count(b[i])==0 || a[i]>b[i]){
            cout<<-1<<endl;
            return;
        }
    }
    vector<pii> ans;
    for(auto [num,idx] : map){
        for(auto it : idx){
            if(b[it] != num){
                ans.push_back({it+1,map[b[it]].back()+1});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto [i,j] : ans) cout<<i<<" "<<j<<endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
    