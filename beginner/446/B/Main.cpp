#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> used(m + 1, false);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<int> a(k);
        for (int j = 0; j < k; j++) {
            cin >> a[j];
        }

        int res = 0;

        for (int j = 0; j < k; j++) {
            if (!used[a[j]]) {
                res = a[j];
                used[res] = true;
                break;
            }
        }

        cout << res << "\n";
    }

}