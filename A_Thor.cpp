#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl
#define pii pair<int,int>
#define ft first
#define sd second

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;
    vector<pii> segTree(2 * n, {0,0});  //{Read,Unread}

    auto merge = [](pii &a, pii &b)
    {
        return {a.ft+b.ft,a.sd+b.sd};
    };

    function<void(int, int, int, int)> update1 = [&](int start, int end, int index, int pos) -> void
    {
        if (start == end)
        {
            segTree[index].sd += 1;
            return;
        }

        int mid = (start + end) / 2;
        if (pos <= mid)
            update1(start, mid, 2 * index, pos);
        else
            update1(mid + 1, end, 2 * index + 1, pos);
        segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
    };

    function<void(int, int, int, int)> update2 = [&](int start, int end, int index, int pos) -> void
    {
        if (start == end)
        {
            segTree[index].ft += segTree[index].sd;
            segTree[index].sd = 0;
            return;
        }

        int mid = (start + end) / 2;
        if (pos <= mid)
            update2(start, mid, 2 * index, pos);
        else
            update2(mid + 1, end, 2 * index + 1, pos);
        segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
    };


    function<void(int, int, int, int)> update3 = [&](int start, int end, int index, int t) -> void
    {
        if (start == end)
        {
            
            return;
        }

        int mid = (start + end) / 2;
        if (t <= mid)
            update3(start, mid, 2 * index, t);
        else
            update3(mid + 1, end, 2 * index + 1, t);
        segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
    };

    

    return 0;
}
