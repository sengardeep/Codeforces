#include <bits/stdc++.h>
using namespace std;

int main() {
    string url;
    cin >> url;

    int size = url.size();
    for (int i = 0; i < size; i++) {
        if (url[i] == '?') {
            i++;
            for (int z = i; z < size; z++) {
                if (url[z] == '=') {
                    cout << ": ";
                }
                else if (url[z] == '&') {
                    cout << endl;
                }
                else {
                    cout << url[z];
                }
            }
            break;
        }
    }
    return 0;
}
