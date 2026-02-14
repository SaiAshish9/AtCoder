#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int count;
    cin >> count;

    vector<string> words(count);
    int maxLength = 0;

    for (int idx = 0; idx < count; idx++) {
        cin >> words[idx];
        maxLength = max(maxLength, (int)words[idx].size());
    }

    for (int idx = 0; idx < count; idx++) {
        int currentLength = words[idx].size();
        int dotCount = (maxLength - currentLength) / 2;

        string dots(dotCount, '.');
        cout << dots << words[idx] << dots << "\n";
    }
}
