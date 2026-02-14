#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W;
    int N;
    cin >> H >> W >> N;

    vector<ll> h(N), w(N);
    for (int i = 0; i < N; i++)
        cin >> h[i] >> w[i];

    multiset<pair<ll,int>> byHeight, byWidth;

    for (int i = 0; i < N; i++) {
        byHeight.insert({h[i], i});
        byWidth.insert({w[i], i});
    }

    vector<ll> ansX(N), ansY(N);

    ll curTop = 1, curLeft = 1;
    ll curH = H, curW = W;

    vector<bool> used(N, false);

    for (int placed = 0; placed < N; placed++) {
        auto itH = byHeight.lower_bound({curH, -1});
        bool done = false;

        while (itH != byHeight.end() && itH->first == curH) {
            int id = itH->second;
            if (!used[id]) {
                ansX[id] = curTop;
                ansY[id] = curLeft;
                used[id] = true;

                curLeft += w[id];
                curW -= w[id];

                byWidth.erase(byWidth.find({w[id], id}));
                itH = byHeight.erase(itH);
                done = true;
                break;
            }
            ++itH;
        }

        if (done) continue;

        auto itW = byWidth.lower_bound({curW, -1});
        while (itW != byWidth.end() && itW->first == curW) {
            int id = itW->second;
            if (!used[id]) {
                ansX[id] = curTop;
                ansY[id] = curLeft;
                used[id] = true;

                curTop += h[id];
                curH -= h[id];

                byHeight.erase(byHeight.find({h[id], id}));
                itW = byWidth.erase(itW);
                break;
            }
            ++itW;
        }
    }

    for (int i = 0; i < N; i++)
        cout << ansX[i] << " " << ansY[i] << "\n";

    return 0;
}
