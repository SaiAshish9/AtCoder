#include <iostream>
#include <vector>
using namespace std;

int f(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N + 1);
    A[0] = 1;

    for (int i = 1; i <= N; i++) {
        int total = 0;
        for (int j = 0; j < i; j++) {
            total += f(A[j]);
        }
        A[i] = total;
    }

    cout << A[N] << endl;
    return 0;
}
