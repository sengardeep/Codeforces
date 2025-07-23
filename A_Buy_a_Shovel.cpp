#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int lastDigi(int n) { return n % 10; }
int32_t main()
{
    fastread();
    int k, r;
    cin >> k >> r;
    int amount = k, ans = 1;
    while (true)
    {
        if(lastDigi(amount) == r || lastDigi(amount) == 0) break;
        amount += k;
        ans++;
    }
    cout << ans << endl;
    return 0;
}