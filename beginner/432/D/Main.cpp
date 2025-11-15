#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct R {
    int64 lx, rx;
    int64 ly, ry;
    R() {}
    R(int64 _lx, int64 _rx, int64 _ly, int64 _ry) : lx(_lx), rx(_rx), ly(_ly), ry(_ry) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    int64 q, r;
    cin >> p >> q >> r;
    vector<char> t(p);
    vector<int64> a(p), b(p);
    for(int i = 0; i < p; ++i) {
        cin >> t[i] >> a[i] >> b[i];
    }

    vector<R> rs;
    rs.emplace_back(0, q - 1, 0, r - 1);

    for(int i = 0; i < p; ++i){
        vector<R> nxt;
        if(t[i] == 'X'){
            int64 Ai = a[i], Bi = b[i];
            for(const R &rc : rs){
                int64 lx1 = rc.lx;
                int64 rx1 = min(rc.rx, Ai - 1);
                if(lx1 <= rx1){
                    nxt.emplace_back(lx1, rx1, rc.ly - Bi, rc.ry - Bi);
                }
                int64 lx2 = max(rc.lx, Ai);
                int64 rx2 = rc.rx;
                if(lx2 <= rx2){
                    nxt.emplace_back(lx2, rx2, rc.ly + Bi, rc.ry + Bi);
                }
            }
        } else {
            int64 Ai = a[i], Bi = b[i];
            for(const R &rc : rs){
                int64 ly1 = rc.ly;
                int64 ry1 = min(rc.ry, Ai - 1);
                if(ly1 <= ry1){
                    nxt.emplace_back(rc.lx - Bi, rc.rx - Bi, ly1, ry1);
                }
                int64 ly2 = max(rc.ly, Ai);
                int64 ry2 = rc.ry;
                if(ly2 <= ry2){
                    nxt.emplace_back(rc.lx + Bi, rc.rx + Bi, ly2, ry2);
                }
            }
        }
        rs.swap(nxt);
    }

    if(rs.empty()){
        cout << 0 << "\n\n";
        return 0;
    }

    vector<int64> xs, ys;
    xs.reserve(rs.size()*2 + 2);
    ys.reserve(rs.size()*2 + 2);
    for(const R &rc : rs){
        xs.push_back(rc.lx);
        xs.push_back(rc.rx + 1);
        ys.push_back(rc.ly);
        ys.push_back(rc.ry + 1);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int nx = (int)xs.size() - 1;
    int ny = (int)ys.size() - 1;
    if(nx <= 0 || ny <= 0){
        cout << 0 << "\n\n";
        return 0;
    }

    const long long MAX_CELLS_FOR_DENSE = 20000000LL;
    bool use_dense = ( (int64)nx * (int64)ny <= MAX_CELLS_FOR_DENSE );
    vector<char> dense;
    unordered_set<long long> sparse;
    if(use_dense){
        dense.assign((size_t)nx * ny, 0);
        for(const R &rc : rs){
            int xi = int(lower_bound(xs.begin(), xs.end(), rc.lx) - xs.begin());
            int xj = int(lower_bound(xs.begin(), xs.end(), rc.rx + 1) - xs.begin());
            int yi = int(lower_bound(ys.begin(), ys.end(), rc.ly) - ys.begin());
            int yj = int(lower_bound(ys.begin(), ys.end(), rc.ry + 1) - ys.begin());
            for(int x = xi; x < xj; ++x){
                long long base = (long long)x * ny;
                for(int y = yi; y < yj; ++y){
                    dense[base + y] = 1;
                }
            }
        }
    } else {
        sparse.reserve(rs.size() * 4);
        for(const R &rc : rs){
            int xi = int(lower_bound(xs.begin(), xs.end(), rc.lx) - xs.begin());
            int xj = int(lower_bound(xs.begin(), xs.end(), rc.rx + 1) - xs.begin());
            int yi = int(lower_bound(ys.begin(), ys.end(), rc.ly) - ys.begin());
            int yj = int(lower_bound(ys.begin(), ys.end(), rc.ry + 1) - ys.begin());
            for(int x = xi; x < xj; ++x){
                for(int y = yi; y < yj; ++y){
                    long long key = (long long)x * ny + y;
                    sparse.insert(key);
                }
            }
        }
    }

    vector<int64> compSizes;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    if(use_dense){
        vector<char> vis((size_t)nx * ny, 0);
        for(int i = 0; i < nx; ++i){
            for(int j = 0; j < ny; ++j){
                long long idx = (long long)i * ny + j;
                if(dense[idx] && !vis[idx]){
                    int64 areaCount = 0;
                    deque<pair<int,int>> dq;
                    dq.emplace_back(i,j);
                    vis[idx] = 1;
                    while(!dq.empty()){
                        auto [cx, cy] = dq.front(); dq.pop_front();
                        int64 w = xs[cx+1] - xs[cx];
                        int64 h = ys[cy+1] - ys[cy];
                        areaCount += w * h;
                        for(int d = 0; d < 4; ++d){
                            int nx_x = cx + dx[d];
                            int ny_y = cy + dy[d];
                            if(nx_x < 0 || nx_x >= nx || ny_y < 0 || ny_y >= ny) continue;
                            long long nidx = (long long)nx_x * ny + ny_y;
                            if(!vis[nidx] && dense[nidx]){
                                vis[nidx] = 1;
                                dq.emplace_back(nx_x, ny_y);
                            }
                        }
                    }
                    compSizes.push_back(areaCount);
                }
            }
        }
    } else {
        unordered_set<long long> visited;
        visited.reserve(sparse.size()*2 + 10);
        for(long long key : sparse){
            if(visited.find(key) != visited.end()) continue;
            int64 areaCount = 0;
            deque<long long> dq;
            dq.push_back(key);
            visited.insert(key);
            while(!dq.empty()){
                long long k = dq.front(); dq.pop_front();
                int cx = int(k / ny);
                int cy = int(k % ny);
                int64 w = xs[cx+1] - xs[cx];
                int64 h = ys[cy+1] - ys[cy];
                areaCount += w * h;
                for(int d = 0; d < 4; ++d){
                    int nx_x = cx + dx[d];
                    int ny_y = cy + dy[d];
                    if(nx_x < 0 || nx_x >= nx || ny_y < 0 || ny_y >= ny) continue;
                    long long nk = (long long)nx_x * ny + ny_y;
                    if(sparse.find(nk) != sparse.end() && visited.find(nk) == visited.end()){
                        visited.insert(nk);
                        dq.push_back(nk);
                    }
                }
            }
            compSizes.push_back(areaCount);
        }
    }

    sort(compSizes.begin(), compSizes.end());
    cout << compSizes.size() << "\n";
    for(size_t i = 0; i < compSizes.size(); ++i){
        if(i) cout << ' ';
        cout << compSizes[i];
    }
    cout << "\n";
}
