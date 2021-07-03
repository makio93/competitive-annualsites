#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説を見てから実装、Test Set2までの得点

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
        vector<set<int>> g(2*n);
        vector<pair<int, pair<int, int>>> edges;
        rep(i, n) rep(j, n) if (a[i][j] == -1) {
            g[i].insert(n+j);
            g[n+j].insert(i);
            edges.emplace_back(b[i][j], make_pair(i, n+j));
        }
        sort(all(edges));
        int res = 0;
        for (auto p : edges) {
            int v1 = p.second.first, v2 = p.second.second;
            vector<bool> visited(2*n);
            function<void(int,int)> dfs = [&](int vi, int pi) {
                if (visited[vi]) return;
                visited[vi] = true;
                for (int t : g[vi]) if (t != pi) dfs(t, vi);
            };
            dfs(v1, v2);
            if (visited[v2]) {
                res += p.first;
                g[v1].erase(v2);
                g[v2].erase(v1);
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
