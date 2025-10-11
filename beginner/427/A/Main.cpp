#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    int mid = n / 2;      
    S.erase(mid, 1);
    cout << S << endl;
    return 0;
}
