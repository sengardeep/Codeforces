#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int32_t main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
       vector<int> mp(26, 0);
        for (char c : s) {
            mp[c - 'a']++;
        }

        int minIdx = -1, maxIdx = -1;
        int minFreq = INT_MAX, maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            if (mp[i] != 0 && mp[i] <= minFreq) {
                minFreq = mp[i];
                minIdx = i;
            }
            if (mp[i] != 0 && mp[i] > maxFreq) {
                maxFreq = mp[i];
                maxIdx = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] - 'a' == minIdx) {
                s[i] = char(maxIdx + 'a');
                break;
            }
        }

        cout << s << endl;
    }
    return 0;
}