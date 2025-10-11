#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ALICE = 0;
const int BOB = 1;

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    string S;
    cin >> S;
    
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int total_moves = 2 * K;

    vector<vector<int>> dp(total_moves + 1, vector<int>(N + 1));

    for (int u = 1; u <= N; ++u) {
        if (S[u - 1] == 'A') {
            dp[0][u] = ALICE;
        } else { 
            dp[0][u] = BOB;
        }
    }

    for (int k = 1; k <= total_moves; ++k) {
        bool is_alice_turn = (k % 2 == 0); 
        
        for (int u = 1; u <= N; ++u) {
            
            if (is_alice_turn) {
                bool alice_can_win = false;
                for (int v : adj[u]) {
                    if (dp[k - 1][v] == ALICE) {
                        alice_can_win = true;
                        break;
                    }
                }
                dp[k][u] = alice_can_win ? ALICE : BOB;

            } else {
                bool bob_can_win = false;
                for (int v : adj[u]) {
                    if (dp[k - 1][v] == BOB) {
                        bob_can_win = true;
                        break;
                    }
                }
                dp[k][u] = bob_can_win ? BOB : ALICE;
            }
        }
    }

    if (dp[total_moves][1] == ALICE) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}