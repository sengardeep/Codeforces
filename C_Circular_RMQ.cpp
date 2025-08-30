#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        vector<int> segTree(4 * n + 1, 0);
        vector<int> lazy(4 * n + 1, 0);

        auto merge = [&](int a, int b)
        { return min(a, b); };

        auto push = [&](int index)
        {
            if (lazy[index] != 0)
            {
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
                segTree[2 * index] += lazy[index];
                segTree[2 * index + 1] += lazy[index];
                lazy[index] = 0;
            }
        };
        function<void(int,int,int)> build = [&](int start,int end,int index)->void{
            if(start==end)
            {
                segTree[index]=v[start];
                return;
            }
            int mid=(start+end)/2;
            build(start,mid,2*index);
            build(mid+1,end,2*index+1);
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };
        function<void(int, int, int, int, int, int)> update = [&](int start, int end, int index, int l, int r, int val) -> void
        {
            if (r < start || end < l)
                return;

            if (l <= start && end <= r)
            {
                segTree[index] += val;
                lazy[index] += val;
                return;
            }

            int mid = (start + end) / 2;
            if (start != end)
                push(index);
            update(start, mid, 2 * index, l, r, val);
            update(mid + 1, end, 2 * index + 1, l, r, val);
            segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
        };
        function<int(int, int, int, int, int)> query = [&](int start, int end, int index, int l, int r) -> int
        {
            if (r < start || end < l)
                return LLONG_MAX;
            if (l <= start && end <= r)
                return segTree[index];

            int mid = (start + end) / 2;
            if (start != end)
                push(index);
            int leftAns = query(start, mid, 2 * index, l, r);
            int rightAns = query(mid + 1, end, 2 * index + 1, l, r);

            return merge(leftAns, rightAns);
        };

        build(0, n - 1, 1);
        int q;
        cin >> q;
        while (q--)
        {
            vector<int> nums;
            string line;
            getline(cin >> ws, line);
            stringstream ss(line);
            int x;
            while (ss >> x)
                nums.push_back(x);

            if (nums.size() == 3)
            {
                int l = nums[0], r = nums[1], val = nums[2];
                if (r < l){
                    update(0,n-1,1,l,n-1,val);
                    update(0,n-1,1,0,r,val);
                }
                else
                    update(0, n - 1, 1, l, r, val);
            }
            else
            {
                int l = nums[0], r = nums[1];
                if (r < l){
                    cout << min(query(0, n - 1, 1, l, n - 1), query(0, n - 1, 1, 0, r)) << endl;
                }
                else
                    cout << query(0, n - 1, 1, l, r) << endl;
            }
        }
    }

    return 0;
}
