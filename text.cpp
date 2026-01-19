#include <bits/stdc++.h>
using namespace std;

int main() {
    // Open a file to write the test case
    ofstream out("hack.txt");
    
    // Constraints to fit within 256KB
    // N = 30,000 integers takes ~60KB
    // We have ~190KB left for operations.
    int N = 30000;
    int H = 1000000000; // 10^9
    
    // Stride 1024 is deadly for hashmaps (Power of 2)
    int STRIDE = 1024;
    
    // Store operations temporarily to count M
    vector<pair<int, int>> ops;
    
    // Estimate size management
    // We stop when we are close to the file limit
    long long current_bytes = 0;
    
    // Header estimate (N M H)
    current_bytes += 30; 
    // Array estimate (30000 * "0 ")
    current_bytes += (N * 2); 
    
    int idx_counter = STRIDE;
    int limit_bytes = 250 * 1024; // 250KB safety limit
    
    while (true) {
        int idx = (idx_counter % N) + 1;
        int val = 0;
        
        // Form the line "idx val\n"
        string line = to_string(idx) + " " + to_string(val) + "\n";
        
        if (current_bytes + line.length() > limit_bytes) {
            break;
        }
        
        ops.push_back({idx, val});
        current_bytes += line.length();
        idx_counter += STRIDE;
    }
    
    int M = ops.size();
    
    // --- OUTPUT TO FILE ---
    out << 1 << "\n"; // T = 1
    out << N << " " << M << " " << H << "\n";
    
    // Output Array
    for(int i=0; i<N; i++) {
        out << "0" << (i == N-1 ? "" : " ");
    }
    out << "\n";
    
    // Output Operations
    for(auto p : ops) {
        out << p.first << " " << p.second << "\n";
    }
    
    out.close();
    cout << "Successfully generated 'hack.txt' with M=" << M << " operations." << endl;
    
    return 0;
}