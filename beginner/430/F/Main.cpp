#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        string s;
        if (n > 1) cin >> s;

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        vector<int> lcnt(n + 1, 0), rcnt(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            if (s[i - 2] == 'L') {
                lcnt[i] = lcnt[i - 1] + 1;
                rcnt[i] = 0;
            } else {
                lcnt[i] = 0;
                rcnt[i] = rcnt[i - 1] + 1;
            }
        }

        vector<int> lp(n + 1, 0), rp(n + 1, 0);
        for (int i = n - 1; i >= 1; --i) {
            if (s[i - 1] == 'L') {
                lp[i] = lp[i + 1] + 1;
                rp[i] = 0;
            } else {
                lp[i] = 0;
                rp[i] = rp[i + 1] + 1;
            }
        }

        vector<int> lreq(n + 1), rreq(n + 1);
        for (int i = 1; i <= n; ++i) {
            lreq[i] = rcnt[i] + lp[i];
            rreq[i] = lcnt[i] + rp[i];
        }

        vector<long long> diff(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            int l = lreq[i] + 1;
            int r = n - rreq[i];
            if (l <= r) {
                diff[l]++;
                if (r + 1 <= n + 1) diff[r + 1]--;
            }
        }

        long long cur = 0;
        for (int i = 1; i <= n; ++i) {
            cur += diff[i];
            cout << cur << (i == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
