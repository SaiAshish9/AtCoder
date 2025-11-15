#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    long long S = 0;
    for (auto x : A) S += x;

    if (S % N != 0) {
        cout << -1 << '\n';
        return 0;
    }

    long long T = S / N;
    vector<long long> D(N);
    for (int i = 0; i < N; ++i) D[i] = A[i] - T;

    vector<int> idxs;
    for (int i = 0; i < N; ++i) {
        if (D[i] != 0) idxs.push_back(i);
    }

    int K = (int)idxs.size();
    if (K == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> dvals(K);
    for (int i = 0; i < K; ++i) dvals[i] = D[idxs[i]];

    int full = (1 << K) - 1;
    int SZ = 1 << K;

    vector<long long> sums(SZ, 0);
    vector<unsigned char> pos(SZ, 0), neg(SZ, 0);

    for (int mask = 1; mask < SZ; ++mask) {
        int lsb = mask & -mask;
        int bit = __builtin_ctz(lsb);
        int prev = mask ^ lsb;
        sums[mask] = sums[prev] + dvals[bit];
        pos[mask] = pos[prev] || (dvals[bit] > 0);
        neg[mask] = neg[prev] || (dvals[bit] < 0);
    }

    vector<int> good_masks;
    good_masks.reserve(SZ);
    for (int mask = 1; mask < SZ; ++mask) {
        if (sums[mask] == 0 && pos[mask] && neg[mask]) {
            good_masks.push_back(mask);
        }
    }

    const int NEG_INF = -1000000000;
    vector<int> dp(SZ, NEG_INF);
    vector<int> parent(SZ, -1);
    dp[0] = 0;

    for (int g : good_masks) {
        int comp = full ^ g;  
        int sub = comp;
        while (true) {
            if (dp[sub] != NEG_INF) {
                int m2 = sub | g;
                if (dp[sub] + 1 > dp[m2]) {
                    dp[m2] = dp[sub] + 1;
                    parent[m2] = g;
                }
            }
            if (sub == 0) break;
            sub = (sub - 1) & comp;
        }
    }

    if (dp[full] < 0) {
        parent[full] = full;
        dp[full] = 1;
    }

    vector<int> groups;
    int mask = full;
    while (mask) {
        int g = parent[mask];
        if (g == -1) {
            g = mask;
        }
        groups.push_back(g);
        mask ^= g;
    }

    vector<tuple<int,int,long long>> ops;

    for (int g : groups) {
        vector<pair<int,long long>> donors;   
        vector<pair<int,long long>> receivers; 

        for (int b = 0; b < K; ++b) {
            if (g & (1 << b)) {
                int idx = idxs[b];    
                long long val = D[idx];
                if (val > 0) {
                    donors.push_back({idx, val});
                } else if (val < 0) {
                    receivers.push_back({idx, -val});
                }
            }
        }

        int i = 0, j = 0;
        while (i < (int)donors.size() && j < (int)receivers.size()) {
            long long di = donors[i].second;
            long long dj = receivers[j].second;
            long long amt = min(di, dj);

            if (amt > 0) {
                int from = donors[i].first + 1;  
                int to   = receivers[j].first + 1;
                ops.emplace_back(from, to, amt);
                donors[i].second -= amt;
                receivers[j].second -= amt;
            }
            if (donors[i].second == 0) ++i;
            if (receivers[j].second == 0) ++j;
        }
    }

    cout << ops.size() << '\n';
    for (auto &t : ops) {
        int x, y;
        long long z;
        tie(x, y, z) = t;
        cout << x << ' ' << y << ' ' << z << '\n';
    }

    return 0;
}
