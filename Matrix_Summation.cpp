#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

template <typename T>
class FenwickTree2D {
private:
    int rows, cols;
    std::vector<std::vector<T>> bit;

    void add(int r, int c, T val) {
        for (int i = r + 1; i <= rows; i += i & -i) {
            for (int j = c + 1; j <= cols; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }

    T prefix_sum(int r, int c) {
        T sum = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            for (int j = c + 1; j > 0; j -= j & -j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

public:
    FenwickTree2D(int r, int c) : rows(r), cols(c) {
        bit.assign(r + 1, std::vector<T>(c + 1, 0));
    }

    // Add a value to the cell (r, c).
    void update(int r, int c, T val) {
        add(r, c, val);
    }

    // Get the sum of the rectangle from (0, 0) to (r, c).
    T query(int r, int c) {
        return prefix_sum(r, c);
    }

    // Get the sum of the rectangle from (r1, c1) to (r2, c2).
    // Note: r1, c1, r2, c2 are 0-based indices.
    T query_range(int r1, int c1, int r2, int c2) {
        return prefix_sum(r2, c2) - prefix_sum(r1 - 1, c2) - prefix_sum(r2, c1 - 1) + prefix_sum(r1 - 1, c1 - 1);
    }
};
void solve() {
    int n;
    cin>>n;
    FenwickTree2D<int> bit = FenwickTree2D<int>(n,n);
    while(true){
        string s;
        cin>>s;
        if(s=="END") return;
        if(s=="SET"){
            int i,j,val;
            cin>>i>>j>>val;
            int x=bit.query_range(i,j,i,j);
            int delta = val-x;
            bit.update(i,j,delta);
        }
        if(s=="SUM"){
            int r1,r2,c1,c2;
            cin>>r1>>c1>>r2>>c2;
            cout<<bit.query_range(r1,c1,r2,c2)<<endl;
        }
    }
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
