// 本番AC

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
        vector<vector<bool>> bads(r, vector<bool>(c));
        vector<vector<int>> deg(r, vector<int>(c));
        rep(i, r) rep(j, c) if (pic[i][j] != '#') {
            rep(ii, 4) {
                int ni = i + di[ii], nj = j + dj[ii];
                if (ni>=0 && ni<r && nj>=0 && nj<c && pic[ni][nj]!='#') deg[i][j]++;
            }
        }
        queue<pair<int, int>> que;
        rep(i, r) rep(j, c) if (deg[i][j] <= 1) {
            bads[i][j] = true;
            if (deg[i][j] == 1) {
                deg[i][j]--;
                que.emplace(i, j);
            }
        }
        while (!que.empty()) {
            auto pi = que.front(); que.pop();
            int i = pi.first, j = pi.second;
            rep(ii, 4) {
                int ni = i + di[ii], nj = j + dj[ii];
                if (ni<0 || ni>=r || nj<0 || nj>=c || pic[ni][nj]=='#' || deg[ni][nj]==0) continue;
                deg[ni][nj]--;
                if (deg[ni][nj] == 0) {
                    bads[ni][nj] = true;
                    que.emplace(ni, nj);
                }
            }
        }
        bool res = true;
        rep(i, r) rep(j, c) if (bads[i][j] && pic[i][j]=='^') res = false;
        if (res) {
            rep(i, r) rep(j, c) if (!bads[i][j] && pic[i][j]=='.') pic[i][j] = '^';
            cout << "Case #" << i0 << ": " << "Possible" << endl;
            rep(i, r) cout << pic[i] << endl;
        }
        else cout << "Case #" << i0 << ": " << "Impossible" << endl;
    }
    return 0;
}
