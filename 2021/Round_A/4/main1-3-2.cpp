#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC、Prim法の場合

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
        rep(i, n) rep(j, n) cin >> a[i][j];
        rep(i, n) rep(j, n) cin >> b[i][j];
        vector<int> r(n), c(n);
        rep(i, n) cin >> r[i];
        rep(i, n) cin >> c[i];
        vector<vector<pair<int, int>>> g(2*n);
        rep(i, n) rep(j, n) {
            if (a[i][j] == -1) {
                g[i].emplace_back(n+j, b[i][j]);
                g[n+j].emplace_back(i, b[i][j]);
            }
        }
        vector<bool> selected(2*n);
        vector<pair<int, int>> dist(2*n);
        int res = 0;
        rep(i, n) rep(j, n) res += b[i][j];
        rep(i, 2*n) {
            int v = -1;
            rep(j, 2*n) if (!selected[j]) {
                if (v==-1 || dist[j].first>dist[v].first) v = j;
            }
            selected[v] = true;
            res -= dist[v].first;
            for (auto p : g[v]) {
                int t = p.first, wi = p.second;
                dist[t] = max(dist[t], { wi, v });
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
