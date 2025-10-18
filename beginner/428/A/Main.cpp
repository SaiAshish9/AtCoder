#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long S, A, B, X; 
    if (!(cin >> S >> A >> B >> X)) {
        return;
    }

    long long cycle_time = A + B;
    long long num_full_cycles = X / cycle_time;
    long long distance_per_cycle = S * A;
    long long total_distance = num_full_cycles * distance_per_cycle;

    long long remaining_time = X % cycle_time;
    long long running_time_in_partial_cycle = min(remaining_time, A);
    long long distance_in_partial_cycle = running_time_in_partial_cycle * S;

    total_distance += distance_in_partial_cycle;
    cout << total_distance << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
