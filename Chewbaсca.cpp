#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> copy;
    while (n)
    {
        copy.push_back(n % 10);
        n /= 10;
    }
    for (long long i = 0; i < copy.size() - 1; i++)
    {
        if (copy[i] >= 5)
            copy[i] = 9 - copy[i];
    }
    reverse(copy.begin(), copy.end());
    if (copy[0] >= 5 && copy[0] < 9)
        copy[0] = 9 - copy[0];

    long long ans = 0;
    for (auto num : copy)
        ans = ans * 10 + num;
    cout << ans << endl;
    return 0;
}