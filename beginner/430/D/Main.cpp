#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> X(N);
    for(int i = 0; i < N; ++i)
        cin >> X[i];
    
    set<ll> coords;
    map<ll, ll> neighborDist;
    
    coords.insert(0);
    neighborDist[0] = LLONG_MAX; 
    ll total = 0; 
    
    for(int i = 0; i < N; ++i) {
        ll x = X[i];
        coords.insert(x);

        auto it = coords.find(x);
        ll left = (it == coords.begin()) ? LLONG_MAX : *prev(it);
        ll right = (next(it) == coords.end()) ? LLONG_MAX : *next(it);

        ll d_left = (left == LLONG_MAX) ? LLONG_MAX : abs(x - left);
        ll d_right = (right == LLONG_MAX) ? LLONG_MAX : abs(right - x);
        ll myDist = min(d_left, d_right);

        neighborDist[x] = myDist;
        total += (myDist == LLONG_MAX) ? 0 : myDist;

        if(left != LLONG_MAX) {
            ll oldDist = neighborDist[left];
            auto itLeft = coords.find(left);
            ll leftLeft = (itLeft == coords.begin()) ? LLONG_MAX : *prev(itLeft);
            ll distLeftLeft = (leftLeft == LLONG_MAX) ? LLONG_MAX : abs(left - leftLeft);
            ll distLeftX  = abs(x - left);
            ll newDist = min(distLeftLeft, distLeftX);
            neighborDist[left] = newDist;
            total += (newDist == LLONG_MAX ? 0 : newDist) - (oldDist == LLONG_MAX ? 0 : oldDist);
        }

        if(right != LLONG_MAX) {
            ll oldDist = neighborDist[right];
            auto itRight = coords.find(right);
            ll rightRight = (next(itRight) == coords.end()) ? LLONG_MAX : *next(itRight);
            ll distRightRight = (rightRight == LLONG_MAX) ? LLONG_MAX : abs(rightRight - right);
            ll distRightX = abs(right - x);
            ll newDist = min(distRightRight, distRightX);
            neighborDist[right] = newDist;
            total += (newDist == LLONG_MAX ? 0 : newDist) - (oldDist == LLONG_MAX ? 0 : oldDist);
        }

        cout << total << '\n';
    }
    return 0;
}
