#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

const int LIMX = 400005;
const int ABC = 26;

struct Qn {
    int L;
    int P;
    int T[ABC];
};

Qn A[LIMX];
int SZ, LS;
bool W[LIMX];

void R0() {
    A[0].L = 0;
    A[0].P = -1;
    fill(A[0].T, A[0].T + ABC, 0);
    SZ = 1;
    LS = 0;
}

void R1(char ch) {
    int ci = ch - 'a';
    int cur = SZ++;
    A[cur].L = A[LS].L + 1;
    fill(A[cur].T, A[cur].T + ABC, 0);

    int p = LS;
    while (p != -1 && A[p].T[ci] == 0) {
        A[p].T[ci] = cur;
        p = A[p].P;
    }

    if (p == -1) {
        A[cur].P = 0;
    } else {
        int q = A[p].T[ci];
        if (A[p].L + 1 == A[q].L) {
            A[cur].P = q;
        } else {
            int cl = SZ++;
            A[cl].L = A[p].L + 1;
            copy(A[q].T, A[q].T + ABC, A[cl].T);
            A[cl].P = A[q].P;

            while (p != -1 && A[p].T[ci] == q) {
                A[p].T[ci] = cl;
                p = A[p].P;
            }
            A[q].P = cl;
            A[cur].P = cl;
        }
    }
    LS = cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;

    while (z--) {
        string S;
        cin >> S;

        R0();
        for (char c : S) R1(c);

        vector<pair<int,int>> ord;
        ord.reserve(SZ);
        for (int i = 0; i < SZ; i++) ord.push_back({A[i].L, i});
        sort(ord.begin(), ord.end());

        for (int i = SZ - 1; i >= 0; i--) {
            int u = ord[i].second;
            bool ok = false;

            for (int j = 0; j < ABC; j++) {
                int v = A[u].T[j];
                if (v != 0) {
                    if (!W[v]) {
                        ok = true;
                        break;
                    }
                }
            }
            W[u] = ok;
        }

        if (W[0]) cout << "Alice\n";
        else cout << "Bob\n";
    }

    return 0;
}
