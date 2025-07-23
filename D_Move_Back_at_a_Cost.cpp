#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getLexicographicallySmallestArray(vector<int> a)
{
    int n = a.size();
    vector<int> result = a;

    for (int i = 0; i < n; ++i)
    {
        vector<int> modified = a;
        int increment = 0;

        for (int j = 0; j < n; ++j)
        {
            modified[j] = (a[(i + j) % n] + increment) % 10;
            if (j == 0)
                increment = 1; // Increment only the first element
        }

        if (modified < result)
        {
            result = modified;
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vector<int> result = getLexicographicallySmallestArray(a);
        for (int x : result)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
