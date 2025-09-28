#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modPow(long long base, long long exp, int mod = MOD) {
    long long result = 1;
    long long cur = base % mod;
    while (exp > 0) {
        if (exp & 1) 
            result = (result * cur) % mod;
        cur = (cur * cur) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, K, N;
    cin >> L >> K >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
    }

    if (N == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Calculate 2^(N-1) mod
    long long pow2 = modPow(2, N - 1);
    // Compute answer N * 2^(N-1) mod
    long long ans = (N * pow2) % MOD;

    cout << ans << "\n";
    return 0;
}
