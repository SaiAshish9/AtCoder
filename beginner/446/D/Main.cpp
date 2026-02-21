#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    unordered_map<long long, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        mp[v] = mp[v - 1] + 1;
        ans = max(ans, mp[v]);
    }
    cout << ans << "\n";
}