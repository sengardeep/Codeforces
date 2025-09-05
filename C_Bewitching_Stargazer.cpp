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

    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        auto oddPart = [](int x)->int{
            return x >> __builtin_ctzll((unsigned long long)x);
        };

        int ans = 0;
        if(k == 1){
            ans = n * (n + 1) / 2;
        }else{
            vector<pair<int,int>> st;
            st.reserve(64);
            st.push_back({1, n});
            while(!st.empty()){
            pair<int,int> top = st.back(); st.pop_back();
            int l = top.first, r = top.second;
            int len = r - l + 1;
            if(len < k) continue;
            int oddLen = oddPart(len);
            if(oddLen < k) continue;

            int m = (l + r) >> 1;
            if(len & 1){
                ans += m;
                int ll = l, lr = m - 1;
                int rl = m + 1, rr = r;

                int lLen = lr - ll + 1;
                if(lLen >= k && oddPart(lLen) >= k) st.push_back({ll, lr});

                int rLen = rr - rl + 1;
                if(rLen >= k && oddPart(rLen) >= k) st.push_back({rl, rr});
            }else{
                int ml = m, mr = m + 1;

                int lLen = ml - l + 1;
                if(lLen >= k && oddPart(lLen) >= k) st.push_back({l, ml});

                int rLen = r - mr + 1;
                if(rLen >= k && oddPart(rLen) >= k) st.push_back({mr, r});
            }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
