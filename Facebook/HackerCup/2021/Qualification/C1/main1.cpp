#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        int n;
        cin >> n;
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        vector<vector<int>> g(n);
        rep(i, n-1) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[ai].push_back(bi);
            g[bi].push_back(ai);
        }
        int res = 0;
        if (n <= 1) res = c[0];
        else {
            vector<int> fval(n), gval(n);
            function<int(int,int,int)> dfs = [&](int v, int p, int val) -> int {
                fval[v] = gval[v] = val + c[v];
                for (int ti : g[v]) if (ti != p) gval[v] = max(gval[v], dfs(ti, v, fval[v]));
                return gval[v];
            };
            dfs(0, -1, 0);
            vector<int> rvals;
            rvals.push_back(c[0]);
            for (int tid : g[0]) rvals.push_back(gval[tid]);
            sort(rvals.rbegin(), rvals.rend());
            rep(i, 2) res += rvals[i];
            res -= c[0];
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
