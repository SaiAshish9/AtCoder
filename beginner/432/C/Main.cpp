#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long p, q, r;
    cin >> p >> q >> r;

    vector<long long> A(p);
    for (int i = 0; i < p; ++i) {
        cin >> A[i];
    }

    long long D = r - q;
    bool first_child = true;
    long long W_max = 2e18 + 7;
    long long W_min = 0;

    for (long long a : A) {
        long long current_W_min = a * q;
        long long current_W_max = a * r;
        W_min = max(W_min, current_W_min);
        if (first_child) {
            W_max = current_W_max;
            first_child = false;
        } else {
            W_max = min(W_max, current_W_max);
        }
    }

    if (W_min > W_max) {
        cout << -1 << endl;
        return 0;
    }

    long long R = (A[0] * q) % D;

    for (long long a : A) {
        if ((a * q) % D != R) {
            cout << -1 << endl;
            return 0;
        }
    }

    long long excess_rem = (W_max - R) % D;
    long long W_opt = W_max - excess_rem;

    if (W_opt < W_min) {
        cout << -1 << endl;
        return 0;
    }

    long long total_large_candies = 0;
    for (long long a : A) {
        long long l_i = (W_opt - a * q) / D;
        total_large_candies += l_i;
    }

    cout << total_large_candies << endl;
}
