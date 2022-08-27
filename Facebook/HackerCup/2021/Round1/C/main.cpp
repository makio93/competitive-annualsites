#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const ll mod = (ll)(1e9) + 7;

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        vector<int> a(n-1), b(n-1), c(n-1);
        rep(i, n-1) {
            cin >> a[i] >> b[i] >> c[i];
            a[i]--; b[i]--;
        }
        vector<unordered_map<int, pair<int, int>>> g(n);
        rep(i, n-1) {
            g[a[i]][b[i]] = { i, 0 };
            g[b[i]][a[i]] = { i, 1 };
        }
        vector<int> deg(n);
        rep(i, n) deg[i] = g[i].size();
        vector<vector<ll>> dcnt(n-1, vector<ll>(2, -1));
        function<ll(int,int)> dfs = [&](int v, int p) -> ll {
            int did = -1, eid = -1;
            if (p == -1) {
                int eid = g[v].begin()->second.first, did2 = g[v].begin()->second.second;
                dfs(g[v].begin()->first, v);
                return 0;
            }
            else {
                eid = g[p][v].first;
                did = g[p][v].second;
                if (dcnt[eid][did] != -1) return dcnt[eid][did];
                ll vsum = 0;
                vector<int> dist(n, INF);
                queue<int> que;
                que.push(v);
                dist[v] = INF;
                while (!que.empty()) {
                    int vi = que.front(); que.pop();
                    int di = dist[vi];
                    for (auto pi : g[vi]) if (pi.first!=v && pi.first!=p && dist[pi.first]==INF) {
                        int ti = pi.first, ei = pi.second.first, ndi = min(di, c[ei]);
                        que.push(ti);
                        dist[ti] = ndi;
                    }
                }
                rep(i2, n) if (dist[i2] != INF) vsum = (vsum + dist[i2]) % mod;
                for (auto pi : g[v]) if (pi.first != p) vsum = (vsum + dfs(pi.first, v)) % mod;
                if (did != -1) dcnt[eid][did] = vsum;
                return vsum;
            }
        };
        rep(i, n) if (deg[i] == 1) dfs(i, -1);
        rep(i, n-1) rep(j, 2) if (dcnt[i][j] == -1) dcnt[i][j] = 0;
        ll ans = 1;
        rep(i, n-1) ans = ans * (dcnt[i][0] + dcnt[i][1]) % mod;
        cout << "Case #" << i0 << ": " << ans << endl;
    }
    return 0;
}
