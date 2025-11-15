#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int ROOT = 3;

long long power(long long b, long long e) {
    long long r = 1;
    b %= MOD;
    while (e > 0) {
        if (e % 2) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return r;
}

long long modinv(long long x) {
    return power(x, MOD - 2);
}

vector<long long> f, invf;

void prep(int n) {
    f.resize(n + 1);
    invf.resize(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * i) % MOD;
    invf[n] = modinv(f[n]);
    for (int i = n - 1; i >= 0; i--) invf[i] = (invf[i + 1] * (i + 1)) % MOD;
}

void ntt(vector<long long>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = power(ROOT, (MOD - 1) / len);
        if (inv) wlen = modinv(wlen);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long long u = a[i + j];
                long long v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = (w * wlen) % MOD;
            }
        }
    }
    if (inv) {
        long long invn = modinv(n);
        for (auto &x : a) x = (x * invn) % MOD;
    }
}

vector<long long> multiply(vector<long long> a, vector<long long> b) {
    int n = 1;
    while (n < (int)(a.size() + b.size() - 1)) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    vector<long long> c(n);
    for (int i = 0; i < n; i++) c[i] = (a[i] * b[i]) % MOD;
    ntt(c, true);
    c.resize(a.size() + b.size() - 1);
    return c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    int vmax = 0;
    for (int i = 0; i < n; i++) { cin >> A[i]; vmax = max(vmax, A[i]); }
    for (int i = 0; i < m; i++) { cin >> B[i]; vmax = max(vmax, B[i]); }

    prep(vmax);

    vector<long long> ca(vmax + 1, 0), cb(vmax + 1, 0);
    for (int x : A) ca[x]++;
    for (int y : B) cb[y]++;

    vector<long long> pb(vmax + 1);
    for (int i = 0; i <= vmax; i++) pb[i] = (cb[i] * invf[i]) % MOD;

    vector<long long> pi(vmax + 1);
    for (int i = 0; i <= vmax; i++) pi[i] = invf[i];

    vector<long long> conv = multiply(pb, pi);

    vector<long long> G(vmax + 1, 0);
    for (int i = 0; i <= vmax; i++) if (i < (int)conv.size()) G[i] = (f[i] * conv[i]) % MOD;

    long long ans = 0;
    for (int i = 1; i <= vmax; i++) ans = (ans + ca[i] * G[i]) % MOD;

    cout << ans << "\n";
}
