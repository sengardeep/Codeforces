// Generator for adversarial testcases targeting unordered_map<long long, long long>
// Compile: g++ -O2 -std=gnu++17 gen_tle_unordered_map_case.cpp -o gen
// Example (heaviest single case): ./gen -t 1 -n 200000 -k 1000000000 > input.txt
// Variant exercising the 'comp' branch (likely NO): ./gen -t 1 -n 200000 -k 1000000000 --skew > input.txt
//
// Why this stresses unordered_map:
// - The keys used by the provided solution are arr[i] % k and brr[i] % k.
// - We emit numbers that are multiples of 2^shift (default shift=20), so their low 20 bits are zero.
// - In typical unordered_map implementations with power-of-two buckets, these keys cluster into the same bucket,
//   making each map operation scan long chains, which often leads to TLE at n = 2e5.
//
// Notes:
// - This respects the problem constraint sum(n) across test cases <= 2e5; it errors out if exceeded.
// - Default parameters generate the heaviest valid input for most judges.
// - Use --skew to make S and T differ while keeping the same collision characteristics.

#include <bits/stdc++.h>
using namespace std;

struct Args {
    long long t = 1;
    long long n = 200000;
    long long k = 1000000000LL;
    int shift = 20;
    bool skew = false;
};

static void print_usage(const char* prog) {
    cerr << "Usage: " << prog << " [options]\n"
         << "Options:\n"
         << "  -t <int>        Number of test cases (default: 1)\n"
         << "  -n <int>        Size of each multiset (default: 200000)\n"
         << "  -k <int>        k value (default: 1000000000)\n"
         << "  --shift <int>   Number of trailing zero bits in values (default: 20)\n"
         << "  --skew          Skew T to differ from S (exercises comp-branch; answer likely NO)\n"
         << "  -h, --help      Show this help message\n";
}

static bool parse_args(int argc, char** argv, Args& a) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-t" && i + 1 < argc) {
            a.t = stoll(argv[++i]);
        } else if (arg == "-n" && i + 1 < argc) {
            a.n = stoll(argv[++i]);
        } else if (arg == "-k" && i + 1 < argc) {
            a.k = stoll(argv[++i]);
        } else if (arg == "--shift" && i + 1 < argc) {
            a.shift = stoi(argv[++i]);
        } else if (arg == "--skew") {
            a.skew = true;
        } else if (arg == "-h" || arg == "--help") {
            print_usage(argv[0]);
            exit(0);
        } else {
            cerr << "Unknown or incomplete option: " << arg << "\n";
            print_usage(argv[0]);
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Args args;
    if (!parse_args(argc, argv, args)) {
        return 1;
    }

    // Respect the global constraint sum(n) <= 2e5
    if (args.t < 1 || args.n < 1 || args.k < 1) {
        cerr << "Error: t, n, and k must be positive.\n";
        return 1;
    }
    if (args.t * args.n > 200000LL) {
        cerr << "Error: sum of n over all test cases must be <= 200000. Got " << (args.t * args.n) << ".\n";
        return 2;
    }
    if (args.shift < 0 || args.shift > 60) {
        cerr << "Error: shift must be between 0 and 60.\n";
        return 1;
    }

    const long long step = 1LL << args.shift; // 2^shift
    const long long max_val = min(1000000000LL, args.k - 1); // ensure values < k and <= 1e9
    long long u = (step > 0) ? (max_val / step + 1) : (max_val + 1); // number of distinct residues we can fit
    if (u <= 0) u = 1;

    // Precompute distinct values that all share the same low 'shift' zero bits.
    vector<long long> vals;
    vals.reserve(static_cast<size_t>(u));
    for (long long i = 0; i < u; ++i) {
        long long v = i * step;
        if (v > max_val) break;
        vals.push_back(v);
    }
    if (vals.empty()) vals.push_back(0);

    cout << args.t << "\n";
    for (long long tc = 0; tc < args.t; ++tc) {
        // Build S by cycling through vals
        vector<long long> S;
        S.reserve(static_cast<size_t>(args.n));
        for (long long i = 0; i < args.n; ++i) {
            S.push_back(vals[i % vals.size()]);
        }

        vector<long long> T;
        T.reserve(static_cast<size_t>(args.n));
        if (!args.skew) {
            T = S;
        } else {
            // Skew: keep first half same, second half add 'step' when possible.
            long long half = args.n / 2;
            for (long long i = 0; i < half; ++i) T.push_back(S[i]);
            for (long long i = half; i < args.n; ++i) {
                long long v = S[i] + step;
                if (v >= args.k || v > 1000000000LL) v = S[i];
                T.push_back(v);
            }
        }

        // Output one test case
        cout << args.n << " " << args.k << "\n";
        for (long long i = 0; i < args.n; ++i) {
            if (i) cout << ' ';
            cout << S[i];
        }
        cout << "\n";
        for (long long i = 0; i < args.n; ++i) {
            if (i) cout << ' ';
            cout << T[i];
        }
        cout << "\n";
    }

    return 0;
}