#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool flag = true;
    while (n--)
    {
        bool x;
        cin >> x;
        if (x == 1)
            flag = false;
    }

    if (flag)
        cout << "EASY" << endl;
    else
        cout << "HARD" << endl;
    return 0;
}