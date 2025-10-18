#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int N, K;
    if (!(cin >> N >> K)) {
        return;
    }

    string S;
    if (!(cin >> S)) {
        return;
    }

    map<string, int> substring_counts;

    for (int i = 0; i <= N - K; ++i) {
        string sub = S.substr(i, K);
        substring_counts[sub]++;
    }

    int max_occurrences = 0;
    for (const auto& pair : substring_counts) {
        if (pair.second > max_occurrences) {
            max_occurrences = pair.second;
        }
    }

    vector<string> result_substrings;
    for (const auto& pair : substring_counts) {
        if (pair.second == max_occurrences) {
            result_substrings.push_back(pair.first);
        }
    }

    cout << max_occurrences << endl;
    for (size_t i = 0; i < result_substrings.size(); ++i) {
        cout << result_substrings[i];
        if (i < result_substrings.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
