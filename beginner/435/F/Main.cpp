#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> P(N + 2);
    vector<int> pos(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        pos[P[i]] = i;
    }
    
    vector<int> left(N + 2, 0), right(N + 2, 0);
    vector<int> parent(N + 2, 0);
    stack<int> st;
    
    for (int i = 1; i <= N; i++) {
        int last = 0;
        while (!st.empty() && P[st.top()] < P[i]) {
            last = st.top();
            st.pop();
        }
        
        if (!st.empty()) {
            right[st.top()] = i;
            parent[i] = st.top();
        }
        
        if (last) {
            left[i] = last;
            parent[last] = i;
        }
        
        st.push(i);
    }
    
    int root = pos[N];
    
    vector<ll> dp_left(N + 2, 0), dp_right(N + 2, 0);
    
    for (int h = 1; h <= N; h++) {
        int i = pos[h];
        
        if (left[i]) {
            int l = left[i];
            dp_left[i] = max(dp_left[l], dp_right[l]) + abs(i - l);
        }
        
        if (right[i]) {
            int r = right[i];
            dp_right[i] = max(dp_left[r], dp_right[r]) + abs(i - r);
        }
    }
    
    ll ans = max(dp_left[root], dp_right[root]);
    cout << ans << "\n";
}
