// 本番,TLE

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
        int n;
        ll x, y;
        cin >> n >> x >> y;
        ll s = (ll)n * (n+1) / 2;
        if (s*x%(x+y) != 0) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        ll tar = s * x / (x+y);
        vector<int> lst;
        auto dfs = [&](auto dfs, int d, int ti) -> bool {
            if (ti == 0) return true;
            if (d == n) return false;
            if (ti >= d+1) {
                lst.push_back(d+1);
                bool ret = dfs(dfs, d+1, ti-(d+1));
                if (ret) return true;
                lst.pop_back();
            }
            bool ret = dfs(dfs, d+1, ti);
            if (ret) return true;
            return false;
        };
        if (!dfs(dfs, 0, tar)) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        sort(all(lst));
        cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
        int m = lst.size();
        cout << m << endl;
        rep(i, m) printf("%d%c", lst[i], (i<m-1?' ':'\n'));
    }
    return 0;
}
