#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_X = 100005;
int BLOCK_SIZE;

struct Query {
    int l, r, x, id;
    bool operator<(const Query& other) const {
        int b1 = l / BLOCK_SIZE;
        int b2 = other.l / BLOCK_SIZE;
        if (b1 != b2) return b1 < b2;
        return r < other.r; // Always move R forward
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Put input.txt in the same folder.\n";
        return 1;
    }

    int n, q;
    if (!(fin >> n >> q)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        fin >> queries[i].l >> queries[i].r >> queries[i].x;
        queries[i].l--; // Convert to 0-based index
        queries[i].r--;
        if (queries[i].l < 0) queries[i].l = 0;
        if (queries[i].r < 0) queries[i].r = 0;
        if (queries[i].l >= n) queries[i].l = n - 1;
        if (queries[i].r >= n) queries[i].r = n - 1;
        queries[i].id = i;
    }

    BLOCK_SIZE = max(1, (int)sqrt((double)max(1, n)));
    sort(queries.begin(), queries.end());

    vector<int> ans(q);
    
    // Group queries by block
    int i = 0;
    while (i < q) {
        int cur_block = queries[i].l / BLOCK_SIZE;
        int mo_right = min(n, (cur_block + 1) * BLOCK_SIZE);
        
        bitset<MAX_X> perm_b;
        perm_b[0] = 1;
        int curr_r = mo_right - 1;

        // Process all queries in this block
        while (i < q && queries[i].l / BLOCK_SIZE == cur_block) {
            int L = queries[i].l;
            int R = queries[i].r;
            int X = queries[i].x;
            int id = queries[i].id;

            if (L < 0 || R < 0 || L >= n || R >= n || L > R) {
                ans[id] = 0;
                i++;
                continue;
            }

            // Case 1: Query fits entirely in one block (Small range)
            if (R < mo_right) {
                bitset<MAX_X> temp_b;
                temp_b[0] = 1;
                for (int j = L; j <= R; j++) {
                    temp_b |= (temp_b << a[j]);
                }
                ans[id] = (X < MAX_X && temp_b[X]) ? 1 : 0;
            } 
            // Case 2: Query spans across blocks (Rollback trick)
            else {
                // Permanently add elements moving right
                while (curr_r < R && curr_r + 1 < n) {
                    curr_r++;
                    perm_b |= (perm_b << a[curr_r]);
                }
                
                // Temporarily add elements moving left
                bitset<MAX_X> temp_b = perm_b;
                for (int j = L; j < mo_right && j < n; j++) {
                    temp_b |= (temp_b << a[j]);
                }
                
                ans[id] = (X < MAX_X && temp_b[X]) ? 1 : 0;
            }
            i++;
        }
    }

    // Write final answers
    for (int i = 0; i < q; i++) {
        fout << (ans[i] ? "Yes\n" : "No\n");
    }

    fin.close();
    fout.close();
    cout << "Done! Answers saved to output.txt\n";

    return 0;
}