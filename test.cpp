#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    ofstream out("input.txt");
    
    // Change these numbers to test different sizes
    int max_n = 100000;
    int max_m = 100000;
    long long max_val = 10000;

    random_device rd;
    mt19937 rng(rd());
    
    // Pick random sizes
    uniform_int_distribution<int> nm_dist(100000, max_n);
    int n = nm_dist(rng);
    int m = nm_dist(rng);

    out << n << " " << m << "\n";

    uniform_int_distribution<long long> val_dist(1, max_val);
    
    // Write Box S
    for(int i = 0; i < n; ++i) {
        out << val_dist(rng) << (i == n - 1 ? "" : " ");
    }
    out << "\n";

    // Write Box T
    for(int i = 0; i < n; ++i) {
        out << val_dist(rng) << (i == n - 1 ? "" : " ");
    }
    out << "\n";

    // Write ranges
    uniform_int_distribution<int> idx_dist(1, n);
    for(int i = 0; i < m; ++i) {
        int l = idx_dist(rng);
        int r = idx_dist(rng);
        if (l > r) swap(l, r);
        out << l << " " << r << "\n";
    }

    out.close();
    cout << "Done! File saved as input.txt\n";
    return 0;
}