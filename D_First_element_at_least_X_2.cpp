#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

/**
 * @file D_First_element_at_least_X_2.cpp
 * @brief Answers point updates and "first index i ≥ l with a[i] ≥ x" queries using a segment tree.
 *
 * Program flow:
 *  - Reads n (array size) and q (number of queries).
 *  - Reads array v[0..n-1].
 *  - Builds a segment tree where each node stores (maxValueInSegment, anIndexInSegment).
 *  - Processes q queries:
 *      - Type 1: "1 pos val" — set v[pos] = val.
 *      - Type 2: "2 x l"   — find the smallest index i ≥ l such that v[i] ≥ x; prints i or -1 if none.
 *
 * Data structure:
 *  - Segment tree stored as vector of pairs (maxValue, index). Internal nodes keep the maximum of children.
 *  - Helper routines (implemented as recursive lambdas):
 *      - build(start, end, index): builds the tree from v.
 *      - update(start, end, index, pos, val): point update at pos with val.
 *      - query(start, end, index, x, l): returns the smallest i ≥ l with v[i] ≥ x, or -1 if not found.
 *
 * Query logic:
 *  - If the current segment lies entirely left of l, skip it.
 *  - If the segment maximum < x, skip it (no candidate in this segment).
 *  - Otherwise, descend left then right to find the leftmost qualifying index.
 *
 * Complexity:
 *  - Build: O(n)
 *  - Each update/query: O(log n)
 *
 * Potential issues and corrections:
 *  1) Missing alias/typedef for `pii`:
 *     - The code uses `vector<pii>` but does not show a definition like `using pii = pair<int,int>;`.
 *       Ensure this alias exists, otherwise the code will not compile.
 *
 *  2) Indexing consistency (off-by-one risks):
 *     - The implementation uses 0-based indices internally (build on [0..n-1], returns 0-based index).
 *     - Many problems (CF/CSES variants) expect 1-based indices for input/output.
 *       If the problem is 1-based:
 *         - Convert inputs: `--pos; --l;`
 *         - Convert output: print `ans + 1` (when ans != -1).
 *
 *  3) Variable shadowing for `x`:
 *     - `int x; cin >> x;` selects the query type, and inside the else-branch another `int x, l;` is declared.
 *       While legal, this shadowing is confusing. Prefer distinct names (e.g., `op`, `need`, `left`).
 *
 *  4) Tie-breaking in merge:
 *     - `merge` uses `max(pii, pii)`. For equal values, `std::pair` comparison prefers larger second (index).
 *       This is harmless here because the query finds the leftmost index by traversing left first and uses
 *       only the first component (max value) for pruning. If you later rely on the stored index for answers,
 *       prefer a merge that keeps the smaller index on ties.
 *
 *  5) Update leaf assignment:
 *     - At leaf, the code sets `(val, start)`. This is correct because at leaf `start == pos`, but using
 *       `(val, pos)` is clearer and avoids confusion.
 *
 *  6) Robustness of inputs:
 *     - No bounds checks are performed on `pos` and `l`. Ensure 0 ≤ pos < n and 0 ≤ l < n (or handle cases
 *       like l ≥ n to immediately return -1) per the problem statement.
 *
 *  7) std::function overhead:
 *     - Using std::function for recursive lambdas can add overhead. For performance-critical constraints,
 *       consider named static functions or generic lambdas without std::function.
 *
 *  8) Edge case n == 0:
 *     - If n can be 0, `build(0, n-1, 1)` is invalid. Typically constraints have n ≥ 1, but validate per problem.
 *
 * I/O:
 *  - Uses fast I/O (sync_with_stdio(false), tie(nullptr)).
 *  - When `LOCAL` is defined, redirects stdin/stdout to files.
 */
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<pii> segTree(4*n);

        auto merge = [](pii a,pii b){
            return max(a,b);
        };
        function<void(int,int,int)> build=[&](int start,int end,int index)->void{
            if(start==end){
                segTree[index]={v[start],start};
                return;
            }

            int mid=(start+end)/2;
            build(start,mid,2*index);
            build(mid+1,end,2*index+1);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };

        function<void(int,int,int,int,int)> update=[&](int start,int end, int index,int pos,int val)->void{
            if(start==end){
                segTree[index]=make_pair(val,start);
                return;
            }

            int mid=(start+end)/2;
            if(pos<=mid) update(start,mid,2*index,pos,val);
            else update(mid+1,end,2*index+1,pos,val);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };

        function<int(int,int,int,int,int)> query=[&](int start,int end,int index,int x,int l)->int{
            if(end < l || segTree[index].first < x) return -1;
            if(start==end) return start;

            int mid=(start+end)/2;
            int leftAns = query(start, mid, 2*index, x, l);
            if(leftAns != -1) return leftAns;
            return query(mid+1, end, 2*index+1, x, l);
        };

        build(0,n-1,1);
        while(q--){
            int x;
            cin>>x;
            if(x==1){
                int pos,val;
                cin>>pos>>val;
                update(0,n-1,1,pos,val);
            }
            else{
                int x,l;
                cin>>x>>l;
                cout<<query(0,n-1,1,x,l)<<endl;
            }
        }
    }
    return 0;
}