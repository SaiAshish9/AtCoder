#include <bits/stdc++.h>
using namespace std;

int lenDigits(long long z) {
    if (z == 0) return 1;
    int c = 0;
    while (z > 0) z /= 10, c++;
    return c;
}

long long modPow10(long long b, int e, long long m) {
    long long r = 1, t = b % m;
    for (int i = 0; i < e; i++) r = (r * t) % m;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int aCount;
    long long modVal;
    cin >> aCount >> modVal;

    vector<long long> arrVals(aCount);
    for (int i = 0; i < aCount; i++) cin >> arrVals[i];

    vector<map<long long,int>> freq(11);
    for (long long x : arrVals) {
        int d = lenDigits(x);
        long long key = (-x % modVal + modVal) % modVal;
        freq[d][key]++;
    }

    long long result = 0;
    for (long long x : arrVals) {
        for (int d = 1; d <= 10; d++) {
            long long p10 = modPow10(10, d, modVal);
            long long rem = (x % modVal * p10) % modVal;
            auto it = freq[d].find(rem);
            if (it != freq[d].end()) result += it->second;
        }
    }

    cout << result;
}
