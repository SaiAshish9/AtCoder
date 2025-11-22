#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;

    long long numerator = X - Z * Y;
    long long denom = Z - 1;

    if (numerator % denom == 0 && numerator / denom >= 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
