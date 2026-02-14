#include <bits/stdc++.h>
using namespace std;

static const int MODULO = 998244353;
static const int LIMIT = 10000000;

int smallestPrime[LIMIT + 1];

long long powerMod(long long base, long long exp) {
    long long result = 1;
    while (exp) {
        if (exp & 1) result = result * base % MODULO;
        base = base * base % MODULO;
        exp >>= 1;
    }
    return result;
}

void buildSmallestPrime() {
    for (int i = 1; i <= LIMIT; i++) smallestPrime[i] = i;
    for (int i = 2; i * i <= LIMIT; i++) {
        if (smallestPrime[i] == i) {
            for (int j = i * i; j <= LIMIT; j += i) {
                if (smallestPrime[j] == j) smallestPrime[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    buildSmallestPrime();

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int length;
        cin >> length;

        vector<int> numbers(length);
        for (int i = 0; i < length; i++) cin >> numbers[i];

        unordered_map<int,int> highestExp, secondHighestExp, highestCount;
        vector<unordered_map<int,int>> factorization(length);

        for (int i = 0; i < length; i++) {
            int value = numbers[i];
            while (value > 1) {
                int prime = smallestPrime[value];
                int exponent = 0;
                while (smallestPrime[value] == prime) {
                    value /= prime;
                    exponent++;
                }
                factorization[i][prime] = exponent;

                if (exponent > highestExp[prime]) {
                    secondHighestExp[prime] = highestExp[prime];
                    highestExp[prime] = exponent;
                    highestCount[prime] = 1;
                } else if (exponent == highestExp[prime]) {
                    highestCount[prime]++;
                } else if (exponent > secondHighestExp[prime]) {
                    secondHighestExp[prime] = exponent;
                }
            }
        }

        long long globalLCM = 1;
        for (auto &[prime, exp] : highestExp) {
            globalLCM = globalLCM * powerMod(prime, exp) % MODULO;
        }

        vector<long long> results(length);

        for (int i = 0; i < length; i++) {
            long long currentLCM = globalLCM;

            for (auto &[prime, exp] : factorization[i]) {
                if (exp == highestExp[prime] && highestCount[prime] == 1) {
                    long long reduction = powerMod(prime, highestExp[prime] - secondHighestExp[prime]);
                    long long inverse = powerMod(reduction, MODULO - 2);
                    currentLCM = currentLCM * inverse % MODULO;
                }
            }

            results[i] = currentLCM;
        }

        for (int i = 0; i < length; i++) {
            cout << results[i] << (i + 1 < length ? ' ' : '\n');
        }
    }
}
