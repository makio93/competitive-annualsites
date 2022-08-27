#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

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
        vector<int> mvals;
        function<int(int,int)> dfs = [&](int v, int p) -> int {
            int add = 0;
            for (int t : g[v]) if (t != p) add = max(add, dfs(t, v));
            return c[v] + add;
        };
        for (int ti : g[0]) mvals.push_back(dfs(ti, 0));
        sort(mvals.rbegin(), mvals.rend());
        int res = c[0];
        rep(i, min(2,(int)(mvals.size()))) res += mvals[i];
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
