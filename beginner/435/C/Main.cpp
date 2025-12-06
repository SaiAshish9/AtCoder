#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N + 1);

    for (int i = 1; i <= N; i++) cin >> A[i];

    long long reach = 1 + A[1] - 1;
    long long i = 1;

    while (i <= reach && i <= N) {
        reach = max(reach, i + A[i] - 1);
        i++;
    }

    reach = min(reach, (long long)N);
    cout << reach << "\n";
}
