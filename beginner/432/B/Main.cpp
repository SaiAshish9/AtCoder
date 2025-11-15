#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(10, 0);
    for (char c : s) cnt[c - '0']++;

    if (cnt[0] == 0) {
        for (int p = 0; p <= 9; ++p)
            for (int q = 0; q < cnt[p]; ++q)
                cout << p;
        cout << '\n';
        return 0;
    }

    for (int p = 1; p <= 9; ++p) {
        if (cnt[p] > 0) {
            cout << p;
            cnt[p]--;
            break;
        }
    }
    for (int q = 0; q < cnt[0]; ++q) cout << 0;
    cnt[0] = 0;
    for (int p = 0; p <= 9; ++p)
        for (int r = 0; r < cnt[p]; ++r)
            cout << p;
    cout << '\n';
    return 0;
}
