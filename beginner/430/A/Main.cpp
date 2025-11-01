#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    
    if (!(cin >> A >> B >> C >> D)) {
        return 1; 
    }

    if (C >= A && D < B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
