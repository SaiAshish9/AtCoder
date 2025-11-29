#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<double> sum(M + 1, 0.0);
    vector<int> cnt(M + 1, 0);

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        sum[A] += B;
        cnt[A] += 1;
    }

    cout << fixed << setprecision(15);
    for (int k = 1; k <= M; k++) {
        cout << sum[k] / cnt[k] << "\n";
    }

    return 0;
}
