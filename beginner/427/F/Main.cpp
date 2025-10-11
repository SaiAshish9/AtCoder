#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int n1 = N / 2;
    int n2 = N - n1;

    vector<pair<ll,bool>> left;
    unordered_map<ll, pair<ll,ll>> right_count; 

    for (int mask = 0; mask < (1 << n1); mask++) {
        if (mask & (mask << 1)) continue;
        ll sum = 0;
        bool last = false;
        for (int i = 0; i < n1; i++) if (mask & (1 << i)) sum = (sum + A[i]) % M;
        last = (mask & (1 << (n1-1))) != 0;
        left.emplace_back(sum, last);
    }

    for (int mask = 0; mask < (1 << n2); mask++) {
        if (mask & (mask << 1)) continue;
        ll sum = 0;
        bool first = false;
        for (int i = 0; i < n2; i++) if (mask & (1 << i)) sum = (sum + A[n1+i]) % M;
        first = (mask & 1) != 0;
        if (first) right_count[sum].second++;
        else right_count[sum].first++;
    }

    ll ans = 0;
    for (auto [l_sum, l_last] : left) {
        ll need = (M - l_sum) % M;
        if (right_count.count(need)) {
            auto [c0, c1] = right_count[need];
            if (!l_last) ans += c0 + c1;
            else ans += c0;
        }
    }

    cout << ans << "\n";
}
