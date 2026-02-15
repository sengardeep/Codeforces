#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

// --- CONFIGURATION ---
const int T_CASES = 1000;      // Number of test cases
const int MAX_N = 2000;       // Max N
const int MAX_VAL = 1000000000; // Max intensity value (10^9)

mt19937 rng(time(0));

// Random helper
int random(int min, int max) {
    return uniform_int_distribution<int>(min, max)(rng);
}

int main() {
    ofstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile || !outFile) return 1;

    inFile << T_CASES << "\n";

    for (int t = 0; t < T_CASES; ++t) {
        int N = random(2, MAX_N); // N must be at least 2
        inFile << N << "\n";

        vector<int> A(N);
        
        // Mode 1: Completely Random (Noise)
        if (t % 3 == 0) {
            for (int i = 0; i < N; ++i) A[i] = random(1, 100); 
        }
        // Mode 2: Many Sparks (e.g., 1 1 2 2 3 3...)
        else if (t % 3 == 1) {
            for (int i = 0; i < N; ++i) A[i] = (i / 2) + 1;
        }
        // Mode 3: Sparse Sparks (Two distant sparks)
        else {
            for (int i = 0; i < N; ++i) A[i] = i + 1; // All distinct initially
            // Force sparks at start and end
            if (N > 5) {
                A[1] = A[0];         // Spark at index 0
                A[N-1] = A[N-2];     // Spark at index N-2
            }
        }

        // Write Input
        for (int i = 0; i < N; ++i) {
            inFile << A[i] << (i == N - 1 ? "" : " ");
        }
        inFile << "\n";

        // --- SOLVER LOGIC FOR OUTPUT ---
        // Logic: If sparks > 1, we must merge them into one chain.
        // Cost = (Index of Last Spark) - (Index of First Spark).
        
        vector<int> sparks;
        for (int i = 0; i < N - 1; ++i) {
            if (A[i] == A[i+1]) {
                sparks.push_back(i); // Store 0-based index of spark
            }
        }

        long long ans = 0;
        if (sparks.size() > 1) {
            ans = sparks.back() - sparks.front();
        }
        
        outFile << ans << "\n";
    }

    inFile.close();
    outFile.close();
    cout << "Generated input.txt and output.txt" << endl;
    return 0;
}