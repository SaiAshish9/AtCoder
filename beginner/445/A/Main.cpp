#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.front() == s.back()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
