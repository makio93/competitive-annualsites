// 学習1回目,自力TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n, -1) {}
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
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n), rg(n);
        UnionFind d(n);
        rep(i, m) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[bi].push_back(ai);
            rg[ai].push_back(bi);
            d.unite(bi, ai);
        }
        vector<int> vs;
        vector<bool> visited(n);
        auto dfs1 = [&](auto dfs1, int vi) -> void {
            visited[vi] = true;
            for (const int& ti : g[vi]) if (!visited[ti]) dfs1(dfs1, ti);
            vs.push_back(vi);
        };
        rep(i, n) if (!visited[i]) dfs1(dfs1, i);
        vector<int> cids(n, -1), slst;
        int cid = 0;
        auto dfs2 = [&](auto dfs2, int vi, int ci) -> void {
            cids[vi] = ci;
            for (const int& ti : rg[vi]) if (cids[ti] == -1) dfs2(dfs2, ti, ci);
        };
        repr(i, n) if (cids[vs[i]] == -1) {
            dfs2(dfs2, vs[i], cid);
            slst.push_back(vs[i]);
            ++cid;
        }
        vector<int> svals(cid);
        rep(i, n) svals[cids[i]]++;
        vector<unordered_set<int>> sh(cid);
        visited.assign(n, false);
        auto dfs3 = [&](auto dfs3, int vi) -> void {
            visited[vi] = true;
            for (const int& ti : rg[vi]) {
                if (cids[ti] != cids[vi]) sh[cids[ti]].insert(cids[vi]);
                else if (!visited[ti]) dfs3(dfs3, ti);
            }
        };
        rep(i, n) if (!visited[i]) dfs3(dfs3, i);
        auto dfs4 = [&](auto dfs4, int vi, int ci=0) -> bool {
            int tci = ci + svals[vi];
            if (tci > k) return false;
            for (const int& ti : sh[vi]) if (!dfs4(dfs4, ti, tci)) return false;
            return true;
        };
        int res = 0;
        rep(i, cid) if (!dfs4(dfs4, i)) res += svals[i];
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
