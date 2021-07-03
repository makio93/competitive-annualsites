#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC、Kruskal法の場合

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return (d[x] = find(d[x]));
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return (find(x) == find(y)); }
    int size(int x) { return -d[find(x)]; }
};

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
        vector<pair<int, pair<int, int>>> edges;
        rep(i, n) rep(j, n) if (a[i][j] == -1) edges.emplace_back(b[i][j], make_pair(i, n+j));
        sort(edges.rbegin(), edges.rend());
        UnionFind uf(2*n);
        int res = 0;
        for (auto p : edges) {
            int bi = p.first, ri = p.second.first, ci = p.second.second;
            if (uf.same(ri, ci)) res += bi;
            else uf.unite(ri, ci);
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
