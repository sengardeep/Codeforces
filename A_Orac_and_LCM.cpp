#include <bits/stdc++.h>
#include <numeric>
using namespace std;

// Custom lcm function for C++14 or earlier
long long lcm(long long a, long long b)
{
    return a / __gcd(a, b) * b;
}

int main()
{
    long long int n, l, g = 0, k, a;
    cin >> n >> a;
    l = a;
    for (long long int i = 1; i <= n - 1; i++)
    {
        cin >> a;
        k = lcm(l, a);
        g = __gcd(g, k);
        l = __gcd(a, l);
    }
    cout << g;
}