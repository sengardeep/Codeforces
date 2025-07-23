#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int NMAX = 200005;

vector<long long> power2(NMAX), invPower2(NMAX), prefix2(NMAX);

// Function to calculate modular inverse of a number using Fermat's Little Theorem
long long modInverse(long long x)
{
    long long res = 1;
    long long exp = MOD - 2;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        exp /= 2;
    }
    return res;
}

// Function to precompute powers of 2 and their modular inverses
void precompute()
{
    power2[0] = invPower2[0] = 1;
    for (int i = 1; i < NMAX; ++i)
    {
        power2[i] = (power2[i - 1] * 2) % MOD;
        invPower2[i] = modInverse(power2[i]);
    }
}

// Function to calculate the number of beautiful subsequences for each test case
void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Compute prefix sum of 2's
    prefix2[0] = (a[0] == 2) ? 1 : 0;
    for (int i = 1; i < n; ++i)
    {
        prefix2[i] = prefix2[i - 1] + (a[i] == 2);
    }

    long long result = 0;
    long long sum = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
        {
            // Update the running sum with the number of 2's seen before
            sum = (sum + prefix2[i - 1]) % MOD;
        }
        else if (a[i] == 3)
        {
            int count2 = prefix2[i - 1];
            // Calculate the contribution from the current 3
            result = (result + sum * invPower2[count2]) % MOD;
        }
    }
    cout << result << endl;
}

int main()
{
    // Precompute powers of 2 and their inverses up to Nmax
    precompute();

    // Solve all test cases
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
