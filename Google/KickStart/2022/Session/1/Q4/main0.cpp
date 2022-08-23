// 本番WA1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

const vector<int> di = { -1, -1, 0, 1, 1, 0 }, dj = { 0, 1, 1, 0, -1, -1 };
const vector<char> cols = { 'B', 'R' };
const vector<string> msgs = { "Impossible", "Blue wins", "Red wins", "Nobody wins" };

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        vector<string> board(n);
        rep(i, n) cin >> board[i];
        vector<int> ccnts(2);
        int res = 3;
        rep(i, n) rep(j, n) rep(j2, 2) if (board[i][j] == cols[j2]) ccnts[j2]++;
        if (abs(ccnts[0]-ccnts[1]) >= 2) res = 0;
        if (res != 0) {
            vector<vector<int>> bg(n*n+2*n);
            rep(i, n) rep(j, n) if (board[i][j] == 'B') {
                rep(i2, 6) {
                    int ni = i + di[i2], nj = j + dj[i2];
                    if (ni<0 || ni>=n || nj<0 || nj>=n || board[ni][nj]!='B') continue;
                    bg[i*n+j].push_back(ni*n+nj);
                    bg[ni*n+nj].push_back(i*n+j);
                }
            }
            int vcnt = 0;
            vector<int> dist(n*n+2*n);
            rep(i, n) if (board[i][0] == 'B') {
                if (dist[i*n+0] != 0) continue;
                int did = i+1;
                bool ok = (n == 1);
                queue<int> que;
                que.push(i*n+0);
                dist[i*n+0] = did;
                while (!que.empty()) {
                    int vi = que.front(); que.pop();
                    for (int ti : bg[vi]) if (dist[ti] == 0) {
                        que.push(ti);
                        dist[ti] = did;
                        if (ti%n == n-1) ok = true;
                    }
                }
                if (!ok) continue;
                if (ccnts[0] < ccnts[1]) {
                    res = 0;
                    break;
                }
                int lcnt = 0, rcnt = 0;
                dist[n*n+i] = dist[n*n+n+i] = did;
                rep(i2, n) if (dist[i2*n+0] == did) {
                    ++lcnt;
                    bg[i2*n+0].push_back(n*n+i);
                    bg[n*n+i].push_back(i2*n+0);
                }
                rep(i2, n) if (dist[i2*n+n-1] == did) {
                    ++rcnt;
                    bg[i2*n+n-1].push_back(n*n+n+i);
                    bg[n*n+n+i].push_back(i2*n+n-1);
                }
                if (lcnt==1 || rcnt==1) {
                    ++vcnt;
                    continue;
                }
                vector<int> ord(n*n+2*n), low(n*n+2*n, INF);
                bool aok = false;
                function<int(int,int,int)> dfs = [&](int vi, int pi, int di) -> int {
                    dist[vi] *= -1;
                    ord[vi] = di;
                    low[vi] = min(low[vi], ord[vi]);
                    bool aps = false;
                    int chcnt = 0;
                    for (int ti : bg[vi]) if (ti != pi) {
                        if (dist[ti] > 0) {
                            ++chcnt;
                            di = dfs(ti, vi, di+1);
                            low[vi] = min(low[vi], low[ti]);
                            if (pi!=-1 && ord[vi]<=low[ti]) aps = true;
                        }
                        else low[vi] = min(low[vi], ord[ti]);
                    }
                    if (vi==-1 && chcnt>=2) aps = true;
                    if (aps && vi<n*n) aok = true;
                    return di;
                };
                dfs(n*n+i, -1, 0);
                if (aok) ++vcnt;
                else {
                    res = 0;
                    break;
                }
            }
            if (res != 0) {
                if (vcnt >= 2) res = 0;
                else if (vcnt == 1) res = 1;
            }
        }
        if (res == 3) {
            vector<vector<int>> rg(n*n+2*n);
            rep(i, n) rep(j, n) if (board[i][j] == 'R') {
                rep(i2, 6) {
                    int ni = i + di[i2], nj = j + dj[i2];
                    if (ni<0 || ni>=n || nj<0 || nj>=n || board[ni][nj]!='R') continue;
                    rg[i*n+j].push_back(ni*n+nj);
                    rg[ni*n+nj].push_back(i*n+j);
                }
            }
            int vcnt = 0;
            vector<int> dist(n*n+2*n);
            rep(i, n) if (board[0][i] == 'R') {
                if (dist[0*n+i] != 0) continue;
                int did = i+1;
                bool ok = (n == 1);
                queue<int> que;
                que.push(0*n+i);
                dist[0*n+i] = did;
                while (!que.empty()) {
                    int vi = que.front(); que.pop();
                    for (int ti : rg[vi]) if (dist[ti] == 0) {
                        que.push(ti);
                        dist[ti] = did;
                        if (ti/n == n-1) ok = true;
                    }
                }
                if (!ok) continue;
                if (ccnts[1] < ccnts[0]) {
                    res = 0;
                    break;
                }
                int ucnt = 0, dcnt = 0;
                dist[n*n+i] = dist[n*n+n+i] = did;
                rep(i2, n) if (dist[0*n+i2] == did) {
                    ++ucnt;
                    rg[0*n+i2].push_back(n*n+i);
                    rg[n*n+i].push_back(0*n+i2);
                }
                rep(i2, n) if (dist[(n-1)*n+i2] == did) {
                    ++dcnt;
                    rg[(n-1)*n+i2].push_back(n*n+n+i);
                    rg[n*n+n+i].push_back((n-1)*n+i2);
                }
                if (ucnt==1 || dcnt==1) {
                    ++vcnt;
                    continue;
                }
                vector<int> ord(n*n+2*n), low(n*n+2*n, INF);
                bool aok = false;
                function<int(int,int,int)> dfs = [&](int vi, int pi, int di) -> int {
                    dist[vi] *= -1;
                    ord[vi] = di;
                    low[vi] = min(low[vi], ord[vi]);
                    bool aps = false;
                    int chcnt = 0;
                    for (int ti : rg[vi]) if (ti != pi) {
                        if (dist[ti] > 0) {
                            ++chcnt;
                            di = dfs(ti, vi, di+1);
                            low[vi] = min(low[vi], low[ti]);
                            if (pi!=-1 && ord[vi]<=low[ti]) aps = true;
                        }
                        else low[vi] = min(low[vi], ord[ti]);
                    }
                    if (vi==-1 && chcnt>=2) aps = true;
                    if (aps && vi<n*n) aok = true;
                    return di;
                };
                dfs(n*n+i, -1, 0);
                if (aok) ++vcnt;
                else {
                    res = 0;
                    break;
                }
            }
            if (res != 0) {
                if (vcnt >= 2) res = 0;
                else if (vcnt == 1) res = 2;
            }
        }
        cout << "Case #" << i0 << ": " << msgs[res] << endl;
    }
    return 0;
}
