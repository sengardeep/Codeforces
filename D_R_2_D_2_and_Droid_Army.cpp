#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m,k;
    cin>>n>>m>>k;
    auto f = [](int n){
        int ans=0;
        while(1<<(ans+1) <= n) ans++;
        return ans;
    };
    // Read the matrix
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    // Build per-column sparse tables over rows
    int LOG = f(n);
    vector<vector<vector<int>>> st(m, vector<vector<int>>(n, vector<int>(LOG+1)));
    for(int col=0; col<m; col++){
        for(int i=0; i<n; i++){
            st[col][i][0] = a[i][col];
        }
        for(int j=1; j<=LOG; j++){
            for(int i=0; i+(1<<j)-1 < n; i++){
                st[col][i][j] = max(st[col][i][j-1], st[col][i + (1<<(j-1))][j-1]);
            }
        }
    }
    // Define query function for range maximum
    auto query = [&](int col, int l, int r) {
        int len = r - l + 1;
        int k = 0;
        while((1 << (k+1)) <= len) k++;
        return max(st[col][l][k], st[col][r - (1 << k) + 1][k]);
    };
    vector<int> ans(m,0);
    int maxLen = 0;
    int l=0,r=0;
    // two-pointer using per-column range maxima
    for(r=0;r<n;r++){
        if(l>r) l=r;
        vector<int> cur(m,0);
        int sum = 0;
        for(int i=0;i<m;i++){
            cur[i] = query(i,l,r);
            sum += cur[i];
        }
        while(l<=r && sum > k){
            l++;
            if(l<=r){
                sum = 0;
                for(int i=0;i<m;i++){
                    cur[i] = query(i,l,r);
                    sum += cur[i];
                }
            }
        }
        if(l<=r && sum <= k){
            int curLen = r-l+1;
            if(maxLen < curLen){
                ans = cur;
                maxLen = curLen;
            }
        }
    }
    for(auto it : ans) cout<<it<<" ";
    return 0;
}
