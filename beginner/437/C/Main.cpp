#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> cost(n);
        long long total_strength = 0;

        for (int i = 0; i < n; i++) {
            long long w, p;
            cin >> w >> p;
            cost[i] = w + p;
            total_strength += p;
        }

        sort(cost.begin(), cost.end());

        long long used = 0;
        int riders = 0;

        for (int i = 0; i < n; i++) {
            if (used + cost[i] <= total_strength) {
                used += cost[i];
                riders++;
            } else {
                break;
            }
        }

        cout << riders << '\n';
    }

}
