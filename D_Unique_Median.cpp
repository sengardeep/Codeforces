#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countGoodSubarrays(const vector<int> &a) {
    int n = a.size();
    vector<int> freq(11, 0);
    long long goodCount = 0;

    for (int l = 0; l < n; ++l) {
        fill(freq.begin(), freq.end(), 0);
        int totalElements = 0;

        for (int r = l; r < n; ++r) {
            freq[a[r]]++;
            totalElements++;

            int count = 0;
            int m1 = -1, m2 = -1;

            for (int x = 1; x <= 10; ++x) {
                count += freq[x];
                if (m1 == -1 && count >= (totalElements + 1) / 2) {
                    m1 = x;
                }
                if (m2 == -1 && count >= (totalElements) / 2 + 1) {
                    m2 = x;
                }
                if (m1 != -1 && m2 != -1) break;
            }

            if (m1 == m2) {
                goodCount++;
            }
        }
    }

    return goodCount;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << countGoodSubarrays(a) << endl;
    }

    return 0;
}
