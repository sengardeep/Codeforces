#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;

    bool flag = true;
    int count1 = 0, count2 = 0;
    while (n)
    {
        if ((n % 10) == 4)
        {
            count1++;
        }
        else if ((n % 10) == 7)
        {
            count2++;
        }
        else {
            flag=false;
            break;
        }
        n /= 10;
    }

    if (count1 > 0 && count2 > 0 && flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}