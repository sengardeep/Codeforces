#include <iostream>
using namespace std;

void printPyramid(int n) {
    // Loop for the upper half of the pyramid
    for (int i = 0; i <= n; i++) {
        // Print leading spaces
        for (int j = 0; j < n - i; j++) {
            cout << "  "; // Two spaces for better alignment
        }
        
        // Print increasing numbers
        for (int j = 0; j <= i; j++) {
            if(i==0) cout<<j;
            else
            cout << j <<" ";
            // if (j < i) cout << " "; // Print space only if it's not the last number
        }
        
        // Print decreasing numbers
        for (int j = i - 1; j >= 0; j--) {
            cout << j;
            if (j > 0) cout << " "; // Print space only if it's not the last number
        }
        
        // Move to the next line
        cout << endl;
    }

    // Loop for the lower half of the pyramid
    for (int i = n - 1; i >= 0; i--) {
        // Print leading spaces
        for (int j = 0; j < n - i; j++) {
            cout << "  "; // Two spaces for better alignment
        }
        
        // Print increasing numbers
        for (int j = 0; j <= i; j++) {
            cout << j << " ";
            // if (j < i) cout << " "; // Print space only if it's not the last number
        }
        
        // Print decreasing numbers
        for (int j = i - 1; j >= 0; j--) {
            cout << j;
            if (j > 0) cout << " "; // Print space only if it's not the last number
        }
        
        // Move to the next line
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    printPyramid(n);
    return 0;
}