#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl;

void solve() {
    int n;
    cin>>n;
    map<int,int> map;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        map[x]++;
    }
    vector<pair<int,int>> v;
    for(auto [num,f] : map){
        v.push_back({f,num});
    }
    sort(begin(v),end(v));
    reverse(begin(v),end(v));
    int ans1=0,ans2=0;
    bool flag=true; //Alice
    for(auto [f,num] : v){
        if(flag){
            if(num%2){
                flag=false;
                // dbg(num);
                ans1 += ((num+1)/2)*f;
                ans2 += (num/2)*f;
            }
            else{
                ans1 += (num/2)*f;
                ans2 += (num/2)*f;
            }
        }
        else{
            if(num%2){
                flag=true;
                ans2 += ((num+1)/2)*f;
                ans1 += (num/2)*f;
            }
            else{
                ans1 += (num/2)*f;
                ans2 += (num/2)*f;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

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
    while (t--) {
        solve();
    }

    return 0;
}
    