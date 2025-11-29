#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        long long H;
        cin >> N >> H;

        long long L = H, R = H;
        long long prev_t = 0;

        bool ok = true;

        for (int i = 0; i < N; i++) {
            long long t, l, u;
            cin >> t >> l >> u;

            long long dt = t - prev_t;

            long long newL = max(1LL, L - dt);
            long long newR = R + dt;

            long long L2 = max(newL, l);
            long long R2 = min(newR, u);

            if (L2 > R2) ok = false;

            L = L2;
            R = R2;
            prev_t = t;
        }

        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
