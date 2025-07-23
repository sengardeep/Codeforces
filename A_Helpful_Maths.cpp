#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> sorted;
    for (int i = 0; i < s.size(); i += 2)
    {
        sorted.push_back((s[i] - '0'));
    }
    sort(sorted.begin(), sorted.end());
    int index = 0;
    for (int i = 0; i < s.size(); i += 2)
    {
        s[i] = ('0' + sorted[index]);
        index++;
    }

    cout << s << endl;
    return 0;
}