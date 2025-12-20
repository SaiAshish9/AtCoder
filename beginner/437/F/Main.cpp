#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 4e18;

struct Node {
    long long v[4];
    Node() {
        for (int i = 0; i < 4; ++i) v[i] = -INF;
    }
};

int n, q;
vector<Node> tree;

void update_node(int idx, long long x, long long y) {
    int tree_idx = idx + n;
    tree[tree_idx].v[0] = x + y;
    tree[tree_idx].v[1] = x - y;
    tree[tree_idx].v[2] = -x + y;
    tree[tree_idx].v[3] = -x - y;

    for (tree_idx >>= 1; tree_idx > 0; tree_idx >>= 1) {
        for (int i = 0; i < 4; ++i) {
            tree[tree_idx].v[i] = max(tree[tree_idx << 1].v[i], tree[tree_idx << 1 | 1].v[i]);
        }
    }
}

long long query(int l, int r, long long x, long long y) {
    long long res_v[4] = {-INF, -INF, -INF, -INF};
    long long query_vals[4] = {x + y, x - y, -x + y, -x - y};
    
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            for (int i = 0; i < 4; ++i) res_v[i] = max(res_v[i], tree[l].v[i]);
            l++;
        }
        if (r & 1) {
            --r;
            for (int i = 0; i < 4; ++i) res_v[i] = max(res_v[i], tree[r].v[i]);
        }
    }

    long long max_dist = 0;
    for (int i = 0; i < 4; ++i) {
        max_dist = max(max_dist, res_v[i] - query_vals[i]);
    }
    return max_dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    tree.assign(2 * n, Node());

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        update_node(i, x, y);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            long long x, y;
            cin >> i >> x >> y;
            update_node(i - 1, x, y);
        } else {
            int l, r;
            long long x, y;
            cin >> l >> r >> x >> y;
            cout << query(l - 1, r, x, y) << "\n";
        }
    }

}