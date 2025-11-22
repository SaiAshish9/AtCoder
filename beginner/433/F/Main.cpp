#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 998244353;

int64 modpow(int64 a, int64 e = MOD - 2)
{
    int64 r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    // if (!(cin >> s))
    //     return 0;
    cin >> s;
    int n = (int)s.size();
    vector<int64> fact(n + 5), ifact(n + 5);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = modpow(fact[n]);
    for (int i = n; i > 0; i--)
        ifact[i - 1] = ifact[i] * i % MOD;
    auto C = [&](int a, int b) -> int64
    {
        if (b < 0 || b > a)
            return 0;
        return fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
    };

    int64 ans = 0;
    for (char da = '0'; da <= '8'; ++da)
    {
        char db = da + 1;
        int total_b = 0;
        for (char c : s)
            if (c == db)
                ++total_b;
        int seen_a = 0;
        int seen_b = 0;
        for (char c : s)
        {
            if (c == da)
            {
                ++seen_a;
            }
            else if (c == db)
            {
                int B_after = total_b - seen_b - 1;
                int A_before = seen_a;
                if (A_before >= 1 && B_after >= 0)
                {
                    ans += C(A_before + B_after, A_before - 1);
                    if (ans >= MOD)
                        ans -= MOD;
                }
                ++seen_b;
            }
        }
    }

    cout << ans % MOD << "\n";
}
