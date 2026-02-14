#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nextCell(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nextCell[i];
    }

    vector<int> state(n + 1, 0); 
    vector<int> answer(n + 1, 0);

    for (int start = 1; start <= n; start++) {
        if (state[start] != 0) continue;

        int current = start;
        vector<int> path;

        while (state[current] == 0) {
            state[current] = 1;
            path.push_back(current);
            current = nextCell[current];
        }

        if (state[current] == 1) {
            int cycleStart = current;
            int node = cycleStart;

            do {
                answer[node] = node;
                state[node] = 2;
                node = nextCell[node];
            } while (node != cycleStart);
        }

        for (int i = (int)path.size() - 1; i >= 0; i--) {
            int node = path[i];
            if (state[node] == 2) continue;

            answer[node] = answer[nextCell[node]];
            state[node] = 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }

}
