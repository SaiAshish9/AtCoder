#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<long long> x(n), y(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> y[i];

        deque<pair<int, long long>> q;

        for (int day = 1; day <= n; ++day) {
            q.push_back({day, x[day - 1]});

            long long need = y[day - 1];
            while (need > 0 && !q.empty()) {
                if (q.front().second <= need) {
                    need -= q.front().second;
                    q.pop_front();
                } else {
                    q.front().second -= need;
                    need = 0;
                }
            }

            while (!q.empty() && (day - q.front().first >= d)) {
                q.pop_front();
            }
        }

        long long ans = 0;
        for (auto &p : q) {
            ans += p.second;
        }

        cout << ans << "\n";
    }

}