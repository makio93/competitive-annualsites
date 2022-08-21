// ヒント有,AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);
const ll BIG = (ll)(1e15);
const string ops = "+-*/";
const vector<int> dy = { -1, 0, 0, 1, 0 }, dx = { 0, 1, -1, 0, 0 };

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, p, m, ar, ac;
        cin >> n >> p >> m >> ar >> ac;
        --ar; --ac;
        vector<char> op(4);
        vector<int> k(4), x(p), y(p), c(p);
        rep(i, 4) cin >> op[i] >> k[i];
        rep(i, p) {
            cin >> y[i] >> x[i] >> c[i];
            x[i]--; y[i]--;
        }
        vector<vector<vector<vector<ll>>>> dist(n, vector<vector<vector<ll>>>(n, vector<vector<ll>>(m+1, vector<ll>(1<<p, LINF))));
        auto opcalc = [&](int mi, int di, ll pval) -> ll {
            ll aval = -(pval - BIG * (mi-1));
            if (di < 4) {
                int oid = ops.find(op[di]);
                if (oid == 0) aval += k[di];
                else if (oid == 1) aval -= k[di];
                else if (oid == 2) aval *= k[di];
                else {
                    if (aval >= 0) aval /= k[di];
                    else aval = -((abs(aval)+k[di]-1)/k[di]);
                }
            }
            return (-aval) + BIG * mi;
        };
        auto add = [&](int mi, int val, ll pval) -> ll {
            ll aval = -(pval - BIG * mi);
            return (-(aval + val)) + BIG * mi;
        };
        auto psearch = [&](int yi, int xi) -> int {
            rep(i2, p) if (y[i2]==yi && x[i2]==xi) return i2;
            return -1;
        };
        priority_queue<tuple<ll, int, int, int, int>, vector<tuple<ll, int, int, int, int>>, greater<tuple<ll, int, int, int, int>>> pq;
        pq.emplace(0, ar, ac, 0, 0);
        dist[ar][ac][0][0] = 0;
        while (!pq.empty()) {
            auto tup = pq.top(); pq.pop();
            ll di = get<0>(tup); int yi = get<1>(tup), xi = get<2>(tup), mi = get<3>(tup), plst = get<4>(tup);
            if (dist[yi][xi][mi][plst] != di) continue;
            rep(ii, 5) {
                int ny = yi + dy[ii], nx = xi + dx[ii];
                if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
                ll ndi = opcalc(mi+1, ii, di);
                if (dist[ny][nx][mi+1][plst] > ndi) {
                    dist[ny][nx][mi+1][plst] = ndi;
                    if (mi+1 < m) pq.emplace(ndi, ny, nx, mi+1, plst);
                }
                int pid = psearch(ny, nx);
                if (pid!=-1 && !((plst>>pid)&1)) {
                    int nplst = plst | (1 << pid);
                    ll tndi = add(mi+1, c[pid], ndi);
                    if (dist[ny][nx][mi+1][nplst] > tndi) {
                        dist[ny][nx][mi+1][nplst] = tndi;
                        if (mi+1 < m) pq.emplace(tndi, ny, nx, mi+1, nplst);
                    }
                }
            }
        }
        ll res = LINF;
        rep(i, n) rep(j, n) if (dist[i][j][m][(1<<p)-1] != LINF) res = min(res, dist[i][j][m][(1<<p)-1]);
        if (res == LINF) cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        else {
            res = -(res - m * BIG);
            cout << "Case #" << i0 << ": " << res << endl;
        }
    }
    return 0;
}
