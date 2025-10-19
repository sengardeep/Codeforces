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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int mx1=v[n-1],mx2=0;
    for(int i=0;i<n-1;i++) {
        mx1=max(mx1,v[i]);
        mx2=max(mx2,abs(v[i]-v[i+1]));
    }
    auto possible = [&](int h) -> bool {
        vector<bool> vis(n,0);
        vector<int> indices;
        int total=0;
        for(int i=0;i<n;i++){
            if(v[i]<=h){
                vis[i]=1;
                indices.push_back(i);
                total++;
            }
        }
        for(int i=0;i<indices.size();i++){
            int idx=indices[i];
            //Left
            if(idx-1>=0 && vis[idx-1]==0 && abs(v[idx]-v[idx-1])<=h){
                vis[idx-1]=1;
                indices.push_back(idx-1);
                total++;
            }
            //Right
            if(idx+1<n && vis[idx+1]==0 && abs(v[idx]-v[idx+1])<=h){
                vis[idx+1]=1;
                indices.push_back(idx+1);
                total++;
            }
        }
        if(total==n) return 1;
        else return 0;
    };
    int ans=mx1;
    int start=0,end=max(mx1,mx2);
    while(start<=end){
        int mid=(start+end)/2;
        if(possible(mid)){
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
//    #endif
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}