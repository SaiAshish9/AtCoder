#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    int Q;
    cin >> N >> Q;
    
    set<pair<ll, ll>> intervals;
    ll total_black = 0;
    
    for (int i = 0; i < Q; i++) {
        ll L, R;
        cin >> L >> R;
        
        auto it = intervals.lower_bound({L, 0});
        
        if (it != intervals.begin()) {
            auto prev_it = prev(it);
            if (prev_it->second >= L - 1) {
                it = prev_it;
            }
        }
        
        ll new_L = L, new_R = R;
        
        while (it != intervals.end()) {
            ll l = it->first, r = it->second;
            
            if (l > new_R + 1) break;
            
            new_L = min(new_L, l);
            new_R = max(new_R, r);
            
            total_black -= (r - l + 1);
            
            it = intervals.erase(it);
        }
        
        intervals.insert({new_L, new_R});
        total_black += (new_R - new_L + 1);
        
        cout << N - total_black << "\n";
    }
}
