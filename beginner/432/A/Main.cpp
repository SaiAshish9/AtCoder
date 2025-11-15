#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> v = {A, B, C};
    sort(v.rbegin(), v.rend()); 
    int ans = v[0]*100 + v[1]*10 + v[2];
    cout << ans << "\n";
}
