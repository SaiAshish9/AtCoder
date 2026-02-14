#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LARGE = (ll)4e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount;
    long long steps;
    cin >> vertexCount >> steps;

    vector<vector<ll>> costMatrix(vertexCount, vector<ll>(vertexCount));
    for (int row = 0; row < vertexCount; row++)
        for (int col = 0; col < vertexCount; col++)
            cin >> costMatrix[row][col];

    vector<vector<ll>> answerMatrix(vertexCount, vector<ll>(vertexCount, LARGE));
    for (int i = 0; i < vertexCount; i++)
        answerMatrix[i][i] = 0;

    auto minPlusMultiply = [&](const vector<vector<ll>>& left,
                               const vector<vector<ll>>& right) {
        vector<vector<ll>> product(vertexCount, vector<ll>(vertexCount, LARGE));
        for (int i = 0; i < vertexCount; i++) {
            for (int mid = 0; mid < vertexCount; mid++) {
                if (left[i][mid] == LARGE) continue;
                for (int j = 0; j < vertexCount; j++) {
                    product[i][j] = min(product[i][j], left[i][mid] + right[mid][j]);
                }
            }
        }
        return product;
    };

    while (steps > 0) {
        if (steps & 1)
            answerMatrix = minPlusMultiply(answerMatrix, costMatrix);
        costMatrix = minPlusMultiply(costMatrix, costMatrix);
        steps >>= 1;
    }

    for (int i = 0; i < vertexCount; i++) {
        cout << answerMatrix[i][i] << "\n";
    }

}
