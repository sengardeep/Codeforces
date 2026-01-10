#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(), x.end()

void solve() {
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    vector<pii> fact;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            fact.pb({i,k/i});
            if(i!=k/i) fact.pb({k/i,i});
        }
    }

    vector<int> row, col;

    int one=0;
    for(int i=0;i<n;i++){
        if(a[i]==1) one++;
        if(a[i]==0 || i==n-1){
            if(one>0) row.pb(one);
            one=0;
        }
    }

    one=0;
    for(int i=0;i<m;i++){
        if(b[i]==1) one++;
        if(b[i]==0 || i==m-1){
            if(one>0) col.pb(one);
            one=0;
        }
    }

    if(row.empty() || col.empty()){
        cout<<0;
        return;
    }

    int maxR = *max_element(all(row));
    int maxC = *max_element(all(col));

    vector<int> cntR(maxR+2), sumR(maxR+2);
    vector<int> cntC(maxC+2), sumC(maxC+2);

    for(int x : row){
        cntR[x]++;
        sumR[x] += x;
    }
    for(int x : col){
        cntC[x]++;
        sumC[x] += x;
    }

    for(int i=maxR;i>=1;i--){
        cntR[i] += cntR[i+1];
        sumR[i] += sumR[i+1];
    }
    for(int i=maxC;i>=1;i--){
        cntC[i] += cntC[i+1];
        sumC[i] += sumC[i+1];
    }

    int ans=0;
    for(auto [x,y] : fact){
        if(x<=maxR && y<=maxC){
            int waysR = sumR[x] - (x-1)*cntR[x];
            int waysC = sumC[y] - (y-1)*cntC[y];
            ans += waysR * waysC;
        }
    }

    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
