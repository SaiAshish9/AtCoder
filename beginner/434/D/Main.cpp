#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    const int SIZE = 2000;
    int N;
    cin >> N;
    
    vector<int> U(N), D(N), L(N), R(N);
    vector<vector<int>> diff(SIZE + 2, vector<int>(SIZE + 2, 0));
    
    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        diff[U[i]][L[i]] += 1;
        diff[U[i]][R[i] + 1] -= 1;
        diff[D[i] + 1][L[i]] -= 1;
        diff[D[i] + 1][R[i] + 1] += 1;
    }
    
    vector<vector<int>> cnt(SIZE + 1, vector<int>(SIZE + 1, 0));
    for (int r = 1; r <= SIZE; r++) {
        for (int c = 1; c <= SIZE; c++) {
            cnt[r][c] = cnt[r][c-1] + diff[r][c];
        }
    }

    for (int r = 1; r <= SIZE; r++) {
        for (int c = 1; c <= SIZE; c++) {
            cnt[r][c] += cnt[r-1][c];
        }
    }
    
    int S = 0;
    vector<vector<int>> ones(SIZE + 1, vector<int>(SIZE + 1, 0));
    for (int r = 1; r <= SIZE; r++) {
        for (int c = 1; c <= SIZE; c++) {
            if (cnt[r][c] > 0) S++;
            if (cnt[r][c] == 1) ones[r][c] = 1;
        }
    }
    
    vector<vector<int>> prefix(SIZE + 1, vector<int>(SIZE + 1, 0));
    for (int r = 1; r <= SIZE; r++) {
        for (int c = 1; c <= SIZE; c++) {
            prefix[r][c] = ones[r][c] + prefix[r][c-1] + prefix[r-1][c] - prefix[r-1][c-1];
        }
    }
    
    auto rect_sum = [&](int u, int d, int l, int r) {
        return prefix[d][r] - prefix[u-1][r] - prefix[d][l-1] + prefix[u-1][l-1];
    };
    
    int total_cells = SIZE * SIZE;
    int U0 = total_cells - S;
    
    for (int k = 0; k < N; k++) {
        int single = rect_sum(U[k], D[k], L[k], R[k]);
        cout << U0 + single << "\n";
    }
    
    return 0;
}