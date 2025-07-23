#include <bits/stdc++.h>
using namespace std;

int main() {
    string value;
    cin >> value;

    int e = 0, g = 0, y = 0, p = 0, t = 0;

    for (char ch : value) {
        if (ch == 'e' || ch == 'E') e++;
        else if (ch == 'g' || ch == 'G') g++;
        else if (ch == 'y' || ch == 'Y') y++;
        else if (ch == 'p' || ch == 'P') p++;
        else if (ch == 't' || ch == 'T') t++;
    }

    // Minimum of all required letters
    int result = min({e, g, y, p, t});
    cout << result << endl;
}
