#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;

vector<int> g[MAXN+1], rg[MAXN+1];
int comp[MAXN+1], order[MAXN+1], used[MAXN+1];
vector<int> compNodes[MAXN+1];
stack<int> st;

int N, M, Q, sccCount = 0;

void dfs1(int v) {
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs1(u);
    st.push(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    for (int u : rg[v])
        if (!comp[u])
            dfs2(u, c);
}

vector<int> dagRev[MAXN+1];  
int blackComp[MAXN+1];      
int indeg[MAXN+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
        if (!used[i])
            dfs1(i);

    while (!st.empty()) {
        int v = st.top(); st.pop();
        if (!comp[v]) {
            sccCount++;
            dfs2(v, sccCount);
        }
    }

    for (int v = 1; v <= N; v++) {
        for (int u : g[v]) {
            if (comp[u] != comp[v]) {
                dagRev[comp[u]].push_back(comp[v]);
            }
        }
    }

    cin >> Q;

    vector<pair<int,int>> queries;
    queries.reserve(Q);

    for(int i = 0; i < Q; i++){
        int t, v;
        cin >> t >> v;
        queries.push_back({t, v});
    }

    for (auto &qr : queries) {
        int t = qr.first;
        int v = qr.second;
        int c = comp[v];

        if (t == 1) {
            if (blackComp[c]) continue;

            queue<int> q;
            q.push(c);
            blackComp[c] = 1;

            while (!q.empty()) {
                int x = q.front(); q.pop();
                for (int p : dagRev[x]) {
                    if (!blackComp[p]) {
                        blackComp[p] = 1;
                        q.push(p);
                    }
                }
            }
        } else {
            cout << (blackComp[c] ? "Yes\n" : "No\n");
        }
    }

}
