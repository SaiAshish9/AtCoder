#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(int start_node, int N, const vector<vector<int>>& adj, vector<int>& dist) {
    long long wznork = 0;
    dist.assign(N + 1, -1);
    queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);

    int farthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        } else if (dist[u] == max_dist) {
            if (u > farthest_node) {
                farthest_node = u;
            }
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return farthest_node;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> temp_dist;
    int E1 = bfs(1, N, adj, temp_dist);

    vector<int> dist_E1;
    int E2 = bfs(E1, N, adj, dist_E1);

    vector<int> dist_E2;
    bfs(E2, N, adj, dist_E2);

    for (int v = 1; v <= N; ++v) {
        int d1 = dist_E1[v];
        int d2 = dist_E2[v];

        if (d1 > d2) {
            cout << E1 << "\n";
        } else if (d2 > d1) {
            cout << E2 << "\n";
        } else {
            cout << max(E1, E2) << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
