#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int u, v;
};

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v;
    }

    int min_deletions = M;
    int max_mask = (1 << N); 

    for (int mask = 0; mask < (1 << (N - 1)); ++mask) {
        int current_deletions = 0;

        for (const auto& edge : edges) {
            int u_idx = edge.u - 1;
            int v_idx = edge.v - 1;
            if (((mask >> u_idx) & 1) == ((mask >> v_idx) & 1)) {
                current_deletions++;
            }
        }

        min_deletions = min(min_deletions, current_deletions);
        
    }

    cout << min_deletions << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}