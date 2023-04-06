// 学習1回目,自力aAC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);

const vector<int> dr = { -1, 0, 0, 1, 0 }, dc = { 0, 1, -1, 0, 0 };
const string ops = "+-*/";
ll calc(ll val, char op, int ki) {
    int oid = ops.find(op);
    if (oid == 0) return val + ki;
    else if (oid == 1) return val - ki;
    else if (oid == 2) return val * ki;
    else {
        if (val >= 0) return val / ki;
        else return -((abs(val) + ki - 1) / ki);
    }
}

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, p, m, ar, ac;
        cin >> n >> p >> m >> ar >> ac;
        --ar; --ac;
        vector<char> op(5);
        vector<int> k(5), c(p);
        rep(i, 4) cin >> op[i] >> k[i];
        op[4] = '+'; k[4] = 0;
        vector ids(n, vector(n, -1));
        rep(i, p) {
            int xi, yi;
            cin >> xi >> yi >> c[i];
            --xi; --yi;
            ids[xi][yi] = i;
        }
        vector dist(m+1, vector(1<<p, vector(n, vector(n, -LINF))));
        priority_queue<tuple<ll, int, int, int, int>> pq;
        dist[0][0][ar][ac] = 0;
        pq.emplace(0, ar, ac, 0, 0);
        while (!pq.empty()) {
            auto [di, ri, ci, si, li] = pq.top(); pq.pop();
            int nli = li + 1;
            if (nli > m) continue;
            rep(i1, 5) {
                int nri = ri + dr[i1], nci = ci + dc[i1];
                if (nri<0 || nri>=n || nci<0 || nci>=n) continue;
                ll ndi = calc(di, op[i1], k[i1]);
                int nsi = si | (ids[nri][nci]==-1 ? 0 : (1<<ids[nri][nci]));
                if (dist[nli][si][nri][nci] < ndi) {
                    dist[nli][si][nri][nci] = ndi;
                    pq.emplace(ndi, nri, nci, si, nli);
                }
                if (nsi == si) continue;
                ll tdi = ndi + c[ids[nri][nci]];
                if (dist[nli][nsi][nri][nci] < tdi) {
                    dist[nli][nsi][nri][nci] = tdi;
                    pq.emplace(tdi, nri, nci, nsi, nli);
                }
            }
        }
        ll res = -LINF;
        rep(i, n) rep(j, n) res = max(res, dist[m][(1<<p)-1][i][j]);
        cout << "Case #" << i0 << ": ";
        if (res == -LINF) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
    }
    return 0;
}
