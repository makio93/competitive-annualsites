// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        vector<int> f(n), p(n);
        rep(i, n) cin >> f[i];
        rep(i, n) {
            cin >> p[i];
            p[i]--;
        }
        vector<vector<int>> rg(n);
        rep(i, n) if (p[i] >= 0) rg[p[i]].push_back(i);
        ll res = 0;
        auto dfs = [&](auto dfs, int vi, int pi=-1) -> int {
            vector<int> rlst;
            for (int ti : rg[vi]) if (ti != pi) rlst.push_back(dfs(dfs, ti, vi));
            sort(all(rlst));
            rep3(i1, 1, (int)(rlst.size())) res += rlst[i1];
            int val = f[vi];
            if (!rlst.empty()) val = max(val, rlst.front());
            return val;
        };
        rep(i, n) if (p[i] == -1) res += dfs(dfs, i);
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
