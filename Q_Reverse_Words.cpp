#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // Input full line

    string word = "";
    for(int i=0;i<s.size();i++) {
        if (s[i] == ' ') {
            reverse(word.begin(), word.end());
            cout << word << " ";
            word = "";
        } else {
            word += s[i];
        }
    }
    reverse(word.begin(), word.end()); // for last word
    cout << word;

    return 0;
}
