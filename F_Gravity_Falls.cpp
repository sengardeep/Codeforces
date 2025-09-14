#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        v[i].resize(k);
        for (int j = 0; j < k; j++) cin >> v[i][j];
    }
    sort(begin(v),end(v),[](vector<int>&a,vector<int>&b){
        return a.size()<b.size();
    });
    int maxSize=v.back().size();
    vector<int> ans(maxSize,LLONG_MAX);
    vector<int> edit;
    edit.pb(0);
    for(auto &vi : v){
        int k=vi.size();
        int s=edit.size();
        for(int i=0;i<s;i++){
            int l=edit[i],r=(i+1<s?edit[i+1]:k);
            bool flag=false;
            for(int j=l;j<r;j++){
                if(ans[j]<vi[j]) break;
                if(ans[j]>vi[j]) {
                    flag=true;
                    break;
                }
            }
            if(flag){
                for(int j=l;j<k;j++) ans[j]=vi[j];
                while(edit.back() > l) edit.pop_back();
                edit.pb(k);
                break;
            }
        }
    }
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
