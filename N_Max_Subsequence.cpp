#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    char prev = '#';
    int ans = 0;

    for(int i=0;i<n;i++) {
        if (s[i] != prev) {
            ans++;
            prev = s[i];
        }
    }

    cout << ans << endl;
    return 0;
}
