// 本番TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<unordered_map<int, int>> g(n);
        rep(i, m) {
            int ai, bi, ci;
            cin >> ai >> bi >> ci;
            --ai; --bi;
            g[ai][bi] = g[bi][ai] = ci;
        }
        vector<int> x(q), y(q);
        vector<unordered_map<int, unordered_set<int>>> xy(n);
        rep(i, q) {
            cin >> x[i] >> y[i];
            x[i]--; y[i]--;
            xy[x[i]][y[i]].insert(i);
        }
        vector<ll> res(q);
        int sn = (int)ceil(n);
        rep(i, n) {
            if ((int)(g[i].size()) >= sn) {
                for (auto& tpi : g[i]) {
                    if (xy[i].find(tpi.first) != xy[i].end()) for (const int& tid : xy[i][tpi.first]) res[tid] += (ll)tpi.second * 2;
                    if ((int)(xy[i].size()) <= (int)(g[tpi.first].size())) {
                        for (auto& tpii : xy[i]) if (g[tpi.first].find(tpii.first) != g[tpi.first].end()) 
                            for (const int& tid : tpii.second) res[tid] += min(tpi.second, g[tpi.first][tpii.first]);
                    }
                    else {
                        for (auto& tpii : g[tpi.first]) if (xy[i].find(tpii.first) != xy[i].end()) 
                            for (const int& tid : xy[i][tpii.first]) res[tid] += min(tpi.second, tpii.second);
                    }
                }
            }
            else {
                for (auto& tpi : xy[i]) {
                    if (g[i].find(tpi.first) != g[i].end()) for (const int& tid : tpi.second) res[tid] += (ll)g[i][tpi.first] * 2;
                    for (auto& tpii : g[i]) if (g[tpii.first].find(tpi.first) != g[tpii.first].end()) 
                        for (const int& tid : tpi.second) res[tid] += min(tpii.second, g[tpii.first][tpi.first]);
                }
            }
        }
        cout << "Case #" << i0 << ": ";
        rep(i, q) cout << res[i] << (i<q-1?' ':'\n');
    }
    return 0;
}
