#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    set<int> called;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        called.insert(x);
    }

    int answer = 0;

    for (int i = 0; i < H; i++) {
        int count = 0;
        for (int j = 0; j < W; j++) {
            if (called.count(A[i][j])) {
                count++;
            }
        }
        answer = max(answer, count);
    }

    cout << answer << endl;
}
