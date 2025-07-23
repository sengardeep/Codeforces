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
        int count = 0, lastDigit = 0;
        lastDigit = n % 10;
        lastDigit -= 1;
        while (n)
        {
            n /= 10;
            count++;
        }
        count = (count * (count + 1)) / 2;
        cout << (10 * lastDigit) + count << endl;
    }
    return 0;
}