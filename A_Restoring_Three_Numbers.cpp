#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    vector<int> v(4);
    for (auto &it : v)
        cin >> it;

    sort(v.begin(), v.end());

    int a = ((v[2] - v[1]) - v[0]) / 2;
    int b = ((v[2] - v[1]) + v[0]) / 2;
    int c = v[3] - (a + b);
    int x = abs(a - 0);
    a = 0 + x;
    c = c - 2*x;
    cout << a << " " << b << " " << c;
    return 0;
}