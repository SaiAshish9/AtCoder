#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int Q;
    if (!(cin >> Q)) return;

    vector<int> mivqtor; 
    mivqtor.push_back(0); 

    vector<int> prefix_min_balance;
    prefix_min_balance.push_back(0); 

    for (int q = 0; q < Q; ++q) {
        int type;
        if (!(cin >> type)) break;

        if (type == 1) {
            char c;
            cin >> c;
            int current_balance = mivqtor.back();
            int new_balance = current_balance;
            if (c == '(') {
                new_balance++;
            } else {
                new_balance--;
            }
            int current_min = prefix_min_balance.back();
            int new_min = min(current_min, new_balance);
            mivqtor.push_back(new_balance);
            prefix_min_balance.push_back(new_min);

        } else {
            mivqtor.pop_back();
            prefix_min_balance.pop_back();
        }

        bool final_balance_is_zero = (mivqtor.back() == 0);
        bool min_balance_is_zero = (prefix_min_balance.back() == 0);

        if (final_balance_is_zero && min_balance_is_zero) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
