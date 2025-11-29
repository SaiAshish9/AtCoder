#include <bits/stdc++.h>
using namespace std;

int main() {
    long long W, B;
    cin >> W >> B;

    long long weightInGrams = W * 1000;
    long long n = weightInGrams / B + 1;

    cout << n << endl;
    return 0;
}
