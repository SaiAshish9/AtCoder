#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int MAXVAL = 500005;

struct BIT {
    vector<ll> tree;
    int n;
    BIT(int size) : n(size + 2), tree(size + 5, 0) {}
    void update(int idx, ll delta) {
        idx++;
        while (idx < n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }
    ll query(int idx) {
        idx++;
        ll sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    BIT bit_count(MAXVAL);
    BIT bit_sum(MAXVAL);

    vector<int> A(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        bit_count.update(A[i], 1);
        bit_sum.update(A[i], A[i]);
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            bit_count.update(A[x], -1);
            bit_sum.update(A[x], -A[x]);
            A[x] = y;
            bit_count.update(A[x], 1);
            bit_sum.update(A[x], A[x]);
        } else {
            int l, r;
            cin >> l >> r;
            if (l > r) {
                cout << (ll)N * l << '\n';
                continue;
            }
            ll count_less = bit_count.query(l - 1);
            ll sum_mid = bit_sum.query(r) - bit_sum.query(l - 1);
            ll count_greater = N - bit_count.query(r);
            ll ans = l * count_less + sum_mid + r * count_greater;
            cout << ans << '\n';
        }
    }

}