#include <bits/stdc++.h>
using namespace std;

static const long long mod = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    sort(b.begin(), b.end());

    vector<long long> pref(m + 1, 0);
    for (int i = 0; i < m; i++) {
        pref[i + 1] = (pref[i] + b[i]) % mod;
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long x = a[i];
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();

        long long left = (x % mod * k % mod - pref[k] + mod) % mod;
        long long right = ((pref[m] - pref[k] + mod) % mod
                          - x % mod * (m - k) % mod + mod) % mod;

        ans = (ans + left + right) % mod;
    }

    cout << ans << '\n';
}
