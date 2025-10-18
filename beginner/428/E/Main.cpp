#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll integer_sqrt_floor(ll n) {
    if (n < 0) return 0;
    ll root = static_cast<ll>(sqrt((long double)n));
    while ((root + 1) * (root + 1) <= n) {
        root++;
    }
    while (root * root > n) {
        root--;
    }
    return root;
}

ll integer_sqrt_ceil(ll n) {
    if (n <= 0) return 1;
    ll root = integer_sqrt_floor(n);
    if (root * root == n) {
        return root;
    } else {
        return root + 1;
    }
}

ll power_of_10(int exp) {
    ll res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= 10;
    }
    return res;
}

void solve() {
    ll C, D;
    cin >> C >> D;
    ll total_count = 0;
    ll max_C_plus_x = C + D;
    ll power_ten_L_minus_1 = 1;
    for (int L = 1; ; ++L) {
        ll power_ten_L = power_ten_L_minus_1 * 10;
        ll C_times_10_L = C * power_ten_L;
        ll P = C_times_10_L + C;
        ll min_k_sq_1 = P + 1;
        ll max_k_sq_1 = P + D;
        ll min_k_sq_2 = C_times_10_L + power_ten_L_minus_1;
        ll max_k_sq_2 = C_times_10_L + power_ten_L - 1;
        ll S_min = max(min_k_sq_1, min_k_sq_2);
        ll S_max = min(max_k_sq_1, max_k_sq_2);
        if (S_min > S_max) {
            if (power_ten_L_minus_1 > max_C_plus_x) break;
            power_ten_L_minus_1 = power_ten_L;
            continue;
        }
        ll K_min = integer_sqrt_ceil(S_min);
        ll K_max = integer_sqrt_floor(S_max);
        if (K_min <= K_max) {
            total_count += (K_max - K_min + 1);
        }
        if (power_ten_L_minus_1 > max_C_plus_x) break;
        power_ten_L_minus_1 = power_ten_L;
        if (L > 19) break; 
    }
    cout << total_count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
