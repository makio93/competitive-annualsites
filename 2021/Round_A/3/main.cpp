#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番提出コード（のちに少し手直し）/AC

int main(){
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int r, c;
        cin >> r >> c;
        vector<vector<ll>> g(r, vector<ll>(c));
        rep(i, r) rep(j, c) cin >> g[i][j];
        priority_queue<pair<ll, pair<int, int>>> unvisited;
        rep(i, r) rep(j, c) unvisited.emplace(g[i][j], pair<int, int>{ i, j });
        auto g2 = g;
        vector<vector<bool>> visited(r, vector<bool>(c));
        while (!unvisited.empty()) {
            pair<ll, pair<int, int>> start;
            do {
                start = unvisited.top(); unvisited.pop();
            } while (visited[start.second.first][start.second.second] && !unvisited.empty());
            if (unvisited.empty() && visited[start.second.first][start.second.second]) break;
            int sy = start.second.first, sx = start.second.second;
            queue<pair<int, int>> que;
            que.emplace(sy, sx);
            visited[sy][sx] = true;
            while (!que.empty()) {
                auto pos = que.front(); que.pop();
                int y = pos.first, x = pos.second;
                ll d = g2[y][x], nd = d - 1;
                const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
                rep(i2, 4) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=r || nx<0 || nx>=c) continue;
                    if (g2[ny][nx] > d) continue;
                    if (visited[ny][nx] && g2[ny][nx]>=nd) continue;
                    que.emplace(ny,nx);
                    g2[ny][nx] = max(g2[ny][nx], nd);
                    visited[ny][nx] = true;
                }
            }
        }
        ll cnt = 0;
        rep(i, r) rep(j, c) cnt += max(0LL, g2[i][j]-g[i][j]);
        cout << "Case #" << i1 << ": " << cnt << endl;
    }
    return 0;
}
