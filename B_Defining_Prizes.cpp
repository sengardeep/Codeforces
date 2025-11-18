#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int, int>
#define pb push_back

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    int sum=0;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    sort(begin(v),end(v));
    reverse(begin(v),end(v));
    vector<int> g;
    int count=1;
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]) count++;
        else{
            g.pb(count);
            count=1;
        }
    }
    g.pb(count);
    int sz=g.size();
    vector<int> pre1(sz), pre2(sz);
    if(sz)
    {
        pre1[0]=g[0];
        for(int i=1;i<sz;i++) pre1[i]=pre1[i-1]+g[i];
        pre2[0]=pre1[0];
        for(int i=1;i<sz;i++) pre2[i]=pre2[i-1]+pre1[i];
    }
    int start=0,end=min(m,sz),ans=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int need=(mid==0) ? 0 : pre2[mid-1];
        if(need<=sum)
        {
            start=mid+1;
            ans=mid;
        }
        else
        {
            end=mid-1;
        }
    }
    if(ans!=0) ans=pre1[ans-1];
    cout<<ans<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": ";
        solve();
    }

    return 0;
}
