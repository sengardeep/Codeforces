#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << 2 << endl;
        if (n == 2)
        {
            cout << 1 << " " << 2 << endl;
            continue;
        }
        int x = n - 1;
        int a = n, b = n - 1;
        while (x--)
        {
            cout << a << " " << b << endl;
            a = (a + b + 1) / 2;
            b--;
        }
    }
    return 0;
}