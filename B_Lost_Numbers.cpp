#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
// #define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back
int ask(int i,int j){
    cout<<"? "<<i<<" "<<j<<endl;
    cout.flush();
    int ans; cin>>ans;
    return ans;
}
void solve()
{
    vector<int> v{4, 8, 15, 16, 23, 42};
    map<int,pii> map;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<6;j++){
            // cerr<<(v[i]*v[j])<<endl;
            map[v[i]*v[j]]={v[i],v[j]};
        }
    }
    vector<int> ans;
    int x=ask(1,2);
    ans.pb(map[x].first);
    ans.pb(map[x].second);
    x=ask(2,3);
    if(ans[0]==map[x].first || ans[1]==map[x].first)
    {
        if(ans[0]==map[x].first)
        swap(ans[0],ans[1]);
        ans.pb(map[x].second);
    }
    else if(ans[0]==map[x].second || ans[1]==map[x].second)
    {
        if(ans[0]==map[x].second)
        swap(ans[0],ans[1]);
        ans.pb(map[x].first);
    }
    x=ask(4,5);
    ans.pb(map[x].first);
    ans.pb(map[x].second);
    x=ask(5,6);
    if(ans[3]==map[x].first || ans[4]==map[x].first)
    {
        if(ans[3]==map[x].first)
        swap(ans[3],ans[4]);
        ans.pb(map[x].second);
    }
    else if(ans[3]==map[x].second || ans[4]==map[x].second)
    {
        if(ans[3]==map[x].second)
        swap(ans[3],ans[4]);
        ans.pb(map[x].first);
    }

    cout << "!";
    for(auto it : ans) cout << " " << it;
    cout << endl;
    cout.flush();
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
