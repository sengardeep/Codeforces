#include <bits/stdc++.h>
using namespace std;

int main() {
    string value;
    cin >> value;

    string smallString = value;

    for (int i = 1; i < value.size(); i++) {
        string sub1 = "", sub2 = "";

        for (int j = 0; j < i; j++) sub1 += value[j];
        for (int j = i; j < value.size(); j++) sub2 += value[j];

        sort(sub1.begin(), sub1.end());
        sort(sub2.begin(), sub2.end());

        string combined = sub1 + sub2;
        if (combined < smallString) smallString = combined;
    }

    cout << smallString << endl;
}
