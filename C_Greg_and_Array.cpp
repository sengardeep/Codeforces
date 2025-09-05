#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

template <typename T>
class FenwickTree {
private:
    vector<T> bit;
    int size;

public:
    FenwickTree(int n) : size(n), bit(n + 1, 0) {}

    // Adds a value to an element at a specific index (0-based).
    void add(int index, T delta) {
        index++; // Convert to 1-based
        for (; index <= size; index += index & -index) {
            bit[index] += delta;
        }
    }

    // Queries the prefix sum up to a specific index (0-based).
    T sum(int index) {
        T ans = 0;
        index++; // Convert to 1-based
        for (; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }

    // Queries the sum of a range from 'left' to 'right' (inclusive, 0-based).
    T query(int left, int right) {
        if (left > right) return 0;
        return sum(right) - sum(left - 1);
    }
};

void solve() {
   int n,m,k;
   cin>>n>>m>>k;
   vector<int> v(n);
   FenwickTree<int> bit1=FenwickTree<int>(n);
   for(int i=0;i<n;i++) 
   {
       cin>>v[i];
    //    bit1.add(i,v[i]);
   }
   vector<tuple<int,int,int>> query(m);
   for(int i=0;i<m;i++) {
    int l,r,d;
    cin>>l>>r>>d;
    query[i]={l-1,r-1,d};
   }
   FenwickTree<int> bit2=FenwickTree<int>(m);

   while(k--){
    int l,r;
    cin>>l>>r;
    --l;
    --r;
    bit2.add(l,1);
    bit2.add(r+1,-1);
   }

   for(int i=0;i<m;i++){
    int contribution = bit2.sum(i);
    // dbg(contribution);
    int l=get<0>(query[i]);
    int r=get<1>(query[i]);
    int d=get<2>(query[i]);
    int x = (contribution*d);
    bit1.add(l,x);
    bit1.add(r+1,-x);
   }


   for(int i=0;i<n;i++) cout<<v[i]+bit1.sum(i)<<" ";
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
//    cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
