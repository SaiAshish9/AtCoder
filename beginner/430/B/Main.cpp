#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    set<string> distinct_patterns;

    for (int r = 0; r <= N - M; ++r) {
        for (int c = 0; c <= N - M; ++c) {
            
            string current_pattern = "";
            
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < M; ++j) {
                    current_pattern += S[r + i][c + j];
                }
            }

            distinct_patterns.insert(current_pattern);
        }
    }

    cout << distinct_patterns.size() << endl;

    return 0;
}