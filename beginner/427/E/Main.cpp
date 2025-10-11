#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <bitset> 

using namespace std;

const int MAX_CELLS = 144;

int solve() {
    int H, W;
    if (!(cin >> H >> W)) return -1;

    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    int R_T = -1, C_T = -1;
    bitset<MAX_CELLS> initial_mask;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int k = i * W + j;
            if (S[i][j] == 'T') {
                R_T = i;
                C_T = j;
            } else if (S[i][j] == '#') {
                initial_mask.set(k);
            }
        }
    }

    if (R_T == -1) return -1;
    int N = H * W;

    // 2. BFS Initialization
    // FIX APPLIED HERE: Using std::unordered_map
    unordered_map<bitset<MAX_CELLS>, int> visited;
    queue<pair<bitset<MAX_CELLS>, int>> q;

    q.push({initial_mask, 0});
    visited[initial_mask] = 0;

    // ... (rest of the code is the same) ...

    const vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    const bitset<MAX_CELLS> GOAL_MASK;

    while (!q.empty()) {
        auto [current_mask, current_ops] = q.front();
        q.pop();

        if (current_mask == GOAL_MASK) {
            return current_ops;
        }

        for (const auto& dir : directions) {
            int dr = dir.first;
            int dc = dir.second;
            
            bitset<MAX_CELLS> next_mask;
            bool is_safe = true;

            for (int k = 0; k < N; ++k) {
                if (current_mask.test(k)) {
                    int r = k / W;
                    int c = k % W;

                    int nr = r + dr;
                    int nc = c + dc;
                    
                    if (nr == R_T && nc == C_T) {
                        is_safe = false;
                        break;
                    }

                    if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                        int nk = nr * W + nc;
                        next_mask.set(nk);
                    }
                }
            }

            if (is_safe) {
                if (next_mask == GOAL_MASK) {
                    return current_ops + 1;
                }

                if (visited.find(next_mask) == visited.end()) {
                    visited[next_mask] = current_ops + 1;
                    q.push({next_mask, current_ops + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << endl;

    return 0;
}