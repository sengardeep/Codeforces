#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> pre(n);
    pre[0] = a[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
    int cost = 1e18;
    vector<int> ans(n, 0); 
    for(int i = 0; i < n; i++) {
        if (pre[i] == 0) continue; 
        int temp = (m + pre[i] - 1) / pre[i]; 
        int x = temp * (i + 1);
        if (x < cost) {
            cost = x;
            fill(ans.begin(), ans.end(), 0);
            for (int j = 0; j <= i; j++) {
                ans[j] = temp;
            }
        }
    }
    vector<int> dp(n + 1, 0);
    vector<int> choice(n + 1, 0); 
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){
                int val=dp[i-j]+pre[j-1];
                if(val>dp[i]){
                    dp[i]=val;
                    choice[i]=j;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int s=pre[i-1];
        if(s==0) continue;
        for(int j=1;j<=n;j++){
            int v=dp[j];
            int need=(m>v)?(m-v):0;
            int k=(need+s-1)/s;
            int tot=k*i+j;
            if (tot<cost){
                cost=tot;
                vector<int> cnt(n,0);
                cnt[i-1]+=k;
                int cur=j;
                while (cur>0){
                    int j=choice[cur];
                    cnt[j-1]+=1;
                    cur-=j;
                }
                fill(ans.begin(),ans.end(),0);
                int sum=0;
                for (int i=n-1;i>=0;--i){
                    sum+=cnt[i];
                    ans[i]=sum;
                }
            }
        }
    }
    cout << cost << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int t=1;
   cin>>t;
   int i=1;
   while(t--){
      cout<<"Case #"<<i++<<": ";
      solve();
   }
   return 0;
}