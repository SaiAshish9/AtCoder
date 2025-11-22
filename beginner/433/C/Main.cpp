#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    int n = S.size();

    vector<pair<int,int>> runs; 
    
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && S[j] == S[i]) j++;
        runs.push_back({S[i] - '0', j - i});
        i = j;
    }

    long long ans = 0;

    for (int k = 0; k + 1 < (int)runs.size(); k++) {
        int d1 = runs[k].first;
        int d2 = runs[k+1].first;
        int L1 = runs[k].second;
        int L2 = runs[k+1].second;

        if (d2 == d1 + 1) {
            ans += min(L1, L2);
        }
    }

    cout << ans << "\n";
}
