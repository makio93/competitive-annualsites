// 自力WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int r, c;
        cin >> r >> c;
        vector<string> pic(r);
        rep(i, r) cin >> pic[i];
        vector<vector<int>> deg(r, vector<int>(c, -1));
        rep(i, r) rep(j, c) if (pic[i][j] == '^') {
            deg[i][j] = 0;
            rep(i2, 4) {
                int ni = i + di[i2], nj = j + dj[i2];
                if (ni<0 || ni>=r || nj<0 || nj>=c || pic[ni][nj]!='^') continue;
                deg[i][j]++;
            }
        }
        vector<vector<bool>> searching(r, vector<bool>(c)), visited(r, vector<bool>(c));
        auto dfs = [&](auto& dfs, int ri, int ci, int pri, int pci) -> bool {
            searching[ri][ci] = true;
            bool rval = false;
            rep(i2, 4) {
                int ni = ri + di[i2], nj = ci + dj[i2];
                if (ni<0 || ni>=r || nj<0 || nj>=c || (ni==pri&&nj==pci) || pic[ni][nj]=='#' || (pic[ni][nj]=='.'&&visited[ni][nj])) continue;
                if (pic[ni][nj]=='^' || searching[ni][nj] || dfs(dfs, ni, nj, ri, ci)) {
                    pic[ri][ci] = '^';
                    deg[ri][ci] = 0;
                    rep(j2, 4) {
                        int ti = ri + di[j2], tj = ci + dj[j2];
                        if (ti>=0 && ti<r && tj>=0 && tj<c && pic[ti][tj]=='^') {
                            deg[ri][ci]++;
                            deg[ti][tj]++;
                        }
                    }
                    rval = true;
                    break;
                }
            }
            searching[ri][ci] = false;
            visited[ri][ci] = true;
            return rval;
        };
        bool ok = true;
        rep(i, r) {
            rep(j, c) if (deg[i][j]>=0 && deg[i][j]<=1) {
                rep(i1, 4) {
                    int ni = i + di[i1], nj = j + dj[i1];
                    if (ni<0 || ni>=r || nj<0 || nj>=c || pic[ni][nj]!='.' || visited[ni][nj]) continue;
                    dfs(dfs, ni, nj, i, j);
                    if (deg[i][j] > 1) break;
                }
                if (deg[i][j] <= 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            cout << "Case #" << i0 << ": " << "Possible" << endl;
            rep(i, r) cout << pic[i] << endl;
        }
        else cout << "Case #" << i0 << ": " << "Impossible" << endl;
    }
    return 0;
}
