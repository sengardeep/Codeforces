#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<char> vis(n + 1, 0);
    for (int x : v) vis[x] = 1;
    set<int> st1, st2;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) st1.insert(i);
        else st2.insert(i);
    }
    auto exclude = [](set<int>& st, int a, int b) -> int {
        if (st.empty()) return -1;
        auto it = st.begin();
        while (it != st.end() && (*it == a || *it == b)) it++;
        if (it != st.end()) return *it;
        return -1;
    };
    auto include = [&](set<int>& st, int num) -> int {
        if (st.empty()) return -1;
        auto it = st.begin();
        if (*it != num) return *it;
        it++;
        if (it != st.end()) return *it;
        return -1;
    };
    for (int i = 0; i < k; i++) {
        int last = v.back();
        int last2 = v[v.size() - 2];
        int x = -1;
        x = exclude(st1, last, last2);
        if (x != -1) {
            st1.erase(x);
        } else {
            x = exclude(st2, last, last2);
            if (x == -1) {
                x = include(st2, last);
                if (x != -1) st2.erase(x);
                else {
                    x = include(st1, last);
                    if (x != -1) st1.erase(x);
                    else {
                        if (!st2.empty()) { 
                            x = *st2.begin(); 
                            st2.erase(st2.begin()); 
                        }
                        else if (!st1.empty()) {
                            x = *st1.begin();
                            st1.erase(st1.begin()); 
                        }
                        else x = 1;
                    }
                }
            } else {
                st2.erase(x);
            }
        }

        v.push_back(x);
        cout << x << " ";
    }
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
