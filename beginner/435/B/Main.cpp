#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    long long ans = 0;

    for (int l = 0; l < N; l++) {
        long long sum = 0;
        for (int r = l; r < N; r++) {
            sum += A[r];

            bool ok = true;
            for (int i = l; i <= r; i++) {
                if (sum % A[i] == 0) { 
                    ok = false;
                    break;
                }
            }

            if (ok) ans++;
        }
    }

    cout << ans << endl;
}
