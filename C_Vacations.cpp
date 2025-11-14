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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> dp(n,vector<int>(5,-1));
    function<int(int,int)> helper=[&](int index,int prev)->int{
        if(index==n) return 0;
        if(dp[index][prev]!=-1) return dp[index][prev];
        if(v[index]==0){
            return dp[index][prev]=1+helper(index+1,0);
        }
        else if(v[index]==1){
            int mn=1e9;
            if(prev==1) mn=1+helper(index+1,0);
            else mn=min({mn,1+helper(index+1,0),helper(index+1,1)});
            return dp[index][prev]=mn;
        }
        else if(v[index]==2){
            int mn=1e9;
            if(prev==2) mn=1+helper(index+1,0);
            else mn=min({mn,1+helper(index+1,0),helper(index+1,2)});
            return dp[index][prev]=mn;
        }
        else{
            int mn=1e9;
            if(prev==1) mn=min(helper(index+1,2),1+helper(index+1,0));
            else if(prev==2) mn=min(helper(index+1,1),1+helper(index+1,0));
            else mn=min({mn,1+helper(index+1,0),helper(index+1,1),helper(index+1,2)});
            return dp[index][prev]=mn;
        }
    };
    cout<<helper(0,4);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}