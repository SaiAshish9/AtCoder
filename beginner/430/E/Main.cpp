#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string &pattern) {
    int n = (int)pattern.size();
    vector<int> lps(n, 0);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) j = lps[j-1];
        if (pattern[i] == pattern[j]) j++;
        lps[i] = j;
    }
    return lps;
}

int KMP(const string &text, const string &pattern) {
    int n = (int)text.size(), m = (int)pattern.size();
    vector<int> lps = buildLPS(pattern);
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) j = lps[j-1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;

        if (A.size() != B.size()) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> countA(2,0), countB(2,0);
        for (char c : A) countA[c-'0']++;
        for (char c : B) countB[c-'0']++;
        if (countA != countB) {
            cout << -1 << "\n";
            continue;
        }

        string doubled = A + A; 
        int pos = KMP(doubled, B);
        cout << pos << "\n";
    }
    return 0;
}
