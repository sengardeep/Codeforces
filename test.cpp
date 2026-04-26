#include <iostream>
using namespace std;

int get_sum(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    int max_sum = -1;
    int best_num = -1;
    
    // Check up to the square root of n
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            
            // Check the first divisor (i)
            int s1 = get_sum(i);
            if (s1 > max_sum || (s1 == max_sum && i < best_num)) {
                max_sum = s1;
                best_num = i;
            }
            
            // Check the matching pair divisor (n / i)
            int div2 = n / i;
            if (div2 != i) {
                int s2 = get_sum(div2);
                if (s2 > max_sum || (s2 == max_sum && div2 < best_num)) {
                    max_sum = s2;
                    best_num = div2;
                }
            }
        }
    }
    
    cout << best_num << "\n";
    return 0;
}