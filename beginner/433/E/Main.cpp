#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        int r, c;
        cin >> r >> c;

        vector<int> rx(r), cy(c);
        for(int i=0;i<r;i++) cin >> rx[i];
        for(int j=0;j<c;j++) cin >> cy[j];

        int mxv = r * c;

        vector<int> posR(mxv+1, -1), posC(mxv+1, -1);
        for(int i=0;i<r;i++) posR[rx[i]] = i;
        for(int j=0;j<c;j++) posC[cy[j]] = j;

        vector<vector<int>> grid(r, vector<int>(c, 0));

        vector<int> ordR, ordC;
        vector<char> usedR(r, 0), usedC(c, 0);

        deque<pii> q;
        bool ok = true;
        int lastR = -1, lastC = -1;

        for(int v = mxv; v >= 1 && ok; --v){
            bool fR = (posR[v] != -1);
            bool fC = (posC[v] != -1);

            if(fR && fC){
                int rr = posR[v], cc = posC[v];
                grid[rr][cc] = v;

                for(int x : ordC) q.emplace_back(rr, x);
                for(int x : ordR) q.emplace_back(x, cc);

                if(!usedR[rr]){
                    usedR[rr] = 1;
                    ordR.push_back(rr);
                    lastR = rr;
                }
                if(!usedC[cc]){
                    usedC[cc] = 1;
                    ordC.push_back(cc);
                    lastC = cc;
                }
            }
            else if(fR){
                int rr = posR[v];
                if(ordC.empty()){ ok = false; break; }
                int cc = lastC;

                grid[rr][cc] = v;

                for(int x : ordC){
                    if(x != cc) q.emplace_back(rr, x);
                }
                if(!usedR[rr]){
                    usedR[rr] = 1;
                    ordR.push_back(rr);
                    lastR = rr;
                }
            }
            else if(fC){
                int cc = posC[v];
                if(ordR.empty()){ ok = false; break; }
                int rr = lastR;

                grid[rr][cc] = v;

                for(int x : ordR){
                    if(x != rr) q.emplace_back(x, cc);
                }
                if(!usedC[cc]){
                    usedC[cc] = 1;
                    ordC.push_back(cc);
                    lastC = cc;
                }
            }
            else{
                if(q.empty()){ ok = false; break; }

                auto p = q.front(); q.pop_front();
                int rr = p.first, cc = p.second;

                if(grid[rr][cc] != 0){
                    bool found = false;
                    while(!q.empty()){
                        p = q.front(); q.pop_front();
                        rr = p.first; cc = p.second;
                        if(grid[rr][cc] == 0){
                            found = true;
                            break;
                        }
                    }
                    if(!found){ ok = false; break; }
                }
                grid[rr][cc] = v;
            }
        }

        if(!ok){
            cout << "No\n";
            continue;
        }

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j] == 0) ok = false;

        if(!ok){
            cout << "No\n";
            continue;
        }

        for(int i=0;i<r;i++){
            int mv = 0;
            for(int j=0;j<c;j++) mv = max(mv, grid[i][j]);
            if(mv != rx[i]) ok = false;
        }

        for(int j=0;j<c;j++){
            int mv = 0;
            for(int i=0;i<r;i++) mv = max(mv, grid[i][j]);
            if(mv != cy[j]) ok = false;
        }

        if(!ok){
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << grid[i][j] << (j+1==c ? '\n' : ' ');
            }
        }
    }
}
