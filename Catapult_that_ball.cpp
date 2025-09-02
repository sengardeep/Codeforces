#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

/**
 * @brief Main function to solve the catapult problem in Byteland.
 * 
 * This program determines how many times Bob can successfully catapult a magic ball from city A to city B.
 * The condition for a successful catapult is that there is no hill between A and B (exclusive) that is higher than the hill at A.
 * In other words, for a query range [l, r] (0-based), it checks if the maximum height in the subarray [l+1, r-1] is less than or equal to v[l].
 * If the subarray [l+1, r-1] is empty (i.e., l+1 > r-1), the condition is trivially true.
 * 
 * The program uses a sparse table for efficient range maximum queries (RMQ) to preprocess the array of hill heights.
 * 
 * Input:
 * - First line: integers n (number of cities/hills) and q (number of queries).
 * - Second line: n integers representing the heights of the hills/cities.
 * - Next q lines: each with two integers l and r (1-based indices of cities).
 * 
 * Output:
 * - A single integer: the count of queries where the catapult condition is satisfied.
 * 
 * Time Complexity:
 * - Preprocessing: O(n log n) for building the sparse table.
 * - Query processing: O(1) per query using RMQ.
 * - Overall: O(n log n + q).
 * 
 * Space Complexity: O(n log n) for the sparse table.
 * 
 * @return int32_t Exit status (0 for success).
 */
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    auto f=[](int n){
        int ans=0;
        while((1<<(ans+1)) <= n) ans++;
        return ans;
    };
    int LOG=f(n);
    vector<vector<int>> st(n,vector<int>(LOG+1));
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
        st[i][0]=v[i];
    }

    //Preprocessing
    for(int j=1;j<=LOG;j++) for(int i=0; i + (1<<j) <= n; i++) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);

    function<int(int,int)> query=[&](int l,int r)->int{
        int len = r-l+1;
        int k=f(len);
        return max(st[l][k],st[r-(1<<k)+1][k]);
    };

    int ans=0;
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        if(l+1 <= r-1){
            int maxHeight = query(l+1,r-1);
            if(maxHeight <= v[l]) ans++;
        } else {
            ans++;
        }
    }

    cout<<ans;
    return 0;
}
