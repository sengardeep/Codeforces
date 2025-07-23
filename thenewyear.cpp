#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int x = (x1 + x2 + x3) / 3;

    cout << (abs(max(x1, max(x2, x3)) - x) + abs(min(x1, min(x2, x3)) - x)) << endl;
    return 0;
}