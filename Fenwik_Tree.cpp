#pragma once
#include <vector>
#include <type_traits>

// Fenwick Tree (Binary Indexed Tree) - 1D and 2D
// - Public API is 0-based indices; internal storage is 1-based.
// - Supports point updates and prefix/range sum queries.
// - Works with any numeric type T that supports default construction (T{}), +, +=, -, <.
// - Time complexity: add/query in O(log N) for 1D, and O(log N * log M) for 2D.
//
// QUICK USAGE (1D):
//   std::vector<long long> a = {1,2,3,4,5};
//   Fenwick1D<long long> ft(a);         // O(n) build
//   ft.add(2, +10);                     // a[2] += 10
//   auto s1 = ft.sumPrefix(3);          // sum of a[0..3]
//   auto s2 = ft.query(1, 3);        // sum of a[1..3]
//   auto idx = ft.lower_bound(12);      // smallest i with sumPrefix(i) >= 12, or -1 if not found
//
// QUICK USAGE (2D):
//   Fenwick2D<long long> fw(3, 4);      // 3 rows, 4 cols
//   fw.add(1, 2, +5);                   // grid[1][2] += 5
//   auto rsum = fw.query(0, 1, 2, 3);// sum over rectangle x:[0..2], y:[1..3]
//
// NOTES:
// - No bounds checking for speed; ensure indices are in range.
// - lower_bound assumes all added deltas are non-negative (so prefix sums are non-decreasing).

template <typename T = long long>
struct Fenwick1D {
    int n = 0;
    std::vector<T> bit; // size n+1, 1-based internal

    Fenwick1D() = default;
    explicit Fenwick1D(int n_) { reset(n_); }

    // O(n) build from array
    explicit Fenwick1D(const std::vector<T>& a) { build(a); }

    void reset(int n_) {
        n = n_;
        bit.assign(n + 1, T{});
    }

    // O(n) build: in-place linear-time Fenwick build
    void build(const std::vector<T>& a) {
        reset((int)a.size());
        for (int i = 1; i <= n; ++i) {
            bit[i] += a[i - 1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    // Point update: a[i] += delta (0-based)
    void update(int i, T delta) {
        for (int x = i + 1; x <= n; x += x & -x) bit[x] += delta;
    }

    // Prefix sum: sum of a[0..i] (0-based). If i < 0, returns 0.
    T sumPrefix(int i) const {
        if (i < 0) return T{};
        T res{};
        for (int x = i + 1; x > 0; x -= x & -x) res += bit[x];
        return res;
    }

    // Range sum: sum of a[l..r] inclusive (0-based). If r < l, returns 0.
    T query(int l, int r) const {
        if (r < l) return T{};
        return sumPrefix(r) - sumPrefix(l - 1);
    }

    // Total sum over entire array
    T total() const { return sumPrefix(n - 1); }

    // lower_bound on prefix sums:
    // Returns the smallest index i (0-based) such that sumPrefix(i) >= target.
    // Requires all updates to be non-negative. If target <= 0, returns 0.
    // Returns -1 if target > total().
    int lower_bound(T target) const {
        if (target <= T{}) return 0;
        if (total() < target) return -1;

        int idx = 0; // this is 1-based "last position with prefix < target"
        T acc{};
        int step = 1;
        while ((step << 1) <= n) step <<= 1; // highest power of two <= n

        for (; step > 0; step >>= 1) {
            int next = idx + step;
            if (next <= n && acc + bit[next] < target) {
                acc += bit[next];
                idx = next;
            }
        }
        // idx is 1-based last position with prefix < target
        // convert to 0-based first position with prefix >= target
        return idx; // because (idx + 1) - 1 = idx
    }
};

template <typename T = long long>
struct Fenwick2D {
    int n = 0, m = 0;
    std::vector<std::vector<T>> bit; // (n+1) x (m+1), 1-based internal

    Fenwick2D() = default;
    Fenwick2D(int n_, int m_) { reset(n_, m_); }

    void reset(int n_, int m_) {
        n = n_;
        m = m_;
        bit.assign(n + 1, std::vector<T>(m + 1, T{}));
    }

    // Build from matrix in O(n*m*log n*log m) by applying adds
    void build(const std::vector<std::vector<T>>& a) {
        int nn = (int)a.size();
        int mm = nn ? (int)a[0].size() : 0;
        reset(nn, mm);
        for (int i = 0; i < nn; ++i)
            for (int j = 0; j < mm; ++j)
                update(i, j, a[i][j]);
    }

    // Point update: grid[x][y] += delta (0-based)
    void update(int x, int y, T delta) {
        for (int i = x + 1; i <= n; i += i & -i)
            for (int j = y + 1; j <= m; j += j & -j)
                bit[i][j] += delta;
    }

    // Prefix sum over rectangle [0..x][0..y] (0-based). If x<0 or y<0, returns 0.
    T sumPrefix(int x, int y) const {
        if (x < 0 || y < 0) return T{};
        T res{};
        for (int i = x + 1; i > 0; i -= i & -i)
            for (int j = y + 1; j > 0; j -= j & -j)
                res += bit[i][j];
        return res;
    }

    // Sum over rectangle [x1..x2][y1..y2] inclusive (0-based). If invalid, returns 0.
    T query(int x1, int y1, int x2, int y2) const {
        if (x2 < x1 || y2 < y1) return T{};
        return sumPrefix(x2, y2)
             - sumPrefix(x1 - 1, y2)
             - sumPrefix(x2, y1 - 1)
             + sumPrefix(x1 - 1, y1 - 1);
    }
};