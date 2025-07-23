#include <bits/stdc++.h>
using namespace std;

long long maxDiff(vector<long long> &v)
{
    long long maxElement = v[v.size() - 1];
    long long minElement = v[0];

    return (maxElement - minElement);
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long w, h;
        cin >> w >> h;
        long long k1, k2;
        cin >> k1;
        vector<long long> v1(k1);
        for (long long i = 0; i < k1; i++)
            cin >> v1[i];
        cin >> k2;
        vector<long long> v2(k2);
        for (long long i = 0; i < k2; i++)
            cin >> v2[i];

        long long k3, k4;
        cin >> k3;
        vector<long long> v3(k3);
        for (long long i = 0; i < k3; i++)
            cin >> v3[i];
        cin >> k4;
        vector<long long> v4(k4);
        for (long long i = 0; i < k4; i++)
            cin >> v4[i];

        long long m1, m2, m3, m4;
        m1 = maxDiff(v1);
        m2 = maxDiff(v2);
        m3 = maxDiff(v3);
        m4 = maxDiff(v4);

        long long ans = 0;
        ans = max({m1 * h, m2 * h, m3 * w, m4 * w});

        cout << ans << endl;
    }
    return 0;
}