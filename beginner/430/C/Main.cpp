#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    vector<int> Pa(N + 1, 0);
    vector<int> Pb(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        Pa[i + 1] = Pa[i];
        Pb[i + 1] = Pb[i];
        if (S[i] == 'a') Pa[i + 1]++;
        else Pb[i + 1]++;
    }

    long long count_pairs = 0;
    int p_min = 0;

    for (int r = 1; r <= N; ++r) {
        while (p_min < r && Pb[p_min] <= Pb[r] - B) p_min++;
        if (p_min >= r) continue;
        int required_a_count = Pa[r] - A;
        if (required_a_count < 0) continue;
        auto it = upper_bound(Pa.begin(), Pa.begin() + r, required_a_count);
        int p_max = distance(Pa.begin(), it) - 1;
        int valid_starts = p_max - p_min + 1;
        if (valid_starts > 0) count_pairs += valid_starts;
    }

    cout << count_pairs << endl;
    return 0;
}
