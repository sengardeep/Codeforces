#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(7);
    for (int i = 0; i < 7; i++)
        cin >> v[i];

    int ans = 0, idx = 0;
    int x = n;
    while (x > 0)
    {
        ans = idx;
        x -= v[idx];
        idx = (idx + 1) % 7;
        
    }
    cout << (ans + 1) % 8 << endl;
    return 0;
}