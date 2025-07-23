#include <bits/stdc++.h>
using namespace std;

int cur;
vector<int> a, p;

void build(vector<int>& idx, int depth) {
    if (idx.empty()) return;

    vector<int> remove_now;
    vector<vector<int>> blocks;
    vector<int> current_block;

    for (int i : idx) {
        if (a[i] == depth) {
            remove_now.push_back(i);
            if (!current_block.empty()) {
                blocks.push_back(current_block);
                current_block.clear();
            }
        } else {
            current_block.push_back(i);
        }
    }

    if (!current_block.empty()) {
        blocks.push_back(current_block);
    }

    // Assign highest available values to elements removed in this round
    for (int i : remove_now) {
        p[i] = cur--;
    }

    // Process surviving blocks recursively
    if (depth % 2 == 1) {
        // Odd = local min → reverse order
        for (int i = (int)blocks.size() - 1; i >= 0; --i) {
            build(blocks[i], depth + 1);
        }
    } else {
        // Even = local max → normal order
        for (int i = 0; i < (int)blocks.size(); ++i) {
            build(blocks[i], depth + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        p.resize(n);
        cur = n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0); // Fill with 0, 1, ..., n-1

        build(idx, 1);

        for (int i = 0; i < n; ++i) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}
