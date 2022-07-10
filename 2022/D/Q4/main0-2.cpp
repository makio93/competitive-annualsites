// 本番WA2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

namespace internal {
    template <class E> struct csr {
        vector<int> start;
        vector<E> elist;
        csr(int n, const vector<pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {
            for (auto e : edges) start[e.first + 1]++;
            for (int i = 1; i <= n; i++) start[i] += start[i - 1];
            auto counter = start;
            for (auto e : edges) elist[counter[e.first]++] = e.second;
        }
    };
    struct scc_graph {
    public:
        scc_graph(int n) : _n(n) {}
        int num_vertices() { return _n; }
        void add_edge(int from, int to) { edges.push_back({from, {to}}); }
        pair<int, vector<int>> scc_ids() {
            auto g = csr<edge>(_n, edges);
            int now_ord = 0, group_num = 0;
            vector<int> visited, low(_n), ord(_n, -1), ids(_n);
            visited.reserve(_n);
            auto dfs = [&](auto self, int v) -> void {
                low[v] = ord[v] = now_ord++;
                visited.push_back(v);
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto to = g.elist[i].to;
                    if (ord[to] == -1) {
                        self(self, to);
                        low[v] = min(low[v], low[to]);
                    }
                    else low[v] = min(low[v], ord[to]);
                }
                if (low[v] == ord[v]) {
                    while (true) {
                        int u = visited.back();
                        visited.pop_back();
                        ord[u] = _n;
                        ids[u] = group_num;
                        if (u == v) break;
                    }
                    group_num++;
                }
            };
            for (int i = 0; i < _n; i++) if (ord[i] == -1) dfs(dfs, i);
            for (auto& x : ids) x = group_num - 1 - x;
            return {group_num, ids};
        }
        vector<vector<int>> scc() {
            auto ids = scc_ids();
            int group_num = ids.first;
            vector<int> counts(group_num);
            for (auto x : ids.second) counts[x]++;
            vector<vector<int>> groups(ids.first);
            for (int i = 0; i < group_num; i++) groups[i].reserve(counts[i]);
            for (int i = 0; i < _n; i++) groups[ids.second[i]].push_back(i);
            return groups;
        }
    private:
        int _n;
        struct edge { int to; };
        vector<pair<int, edge>> edges;
    };
}

struct scc_graph {
public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}
    void add_edge(int from, int to) { internal.add_edge(from, to); }
    vector<vector<int>> scc() { return internal.scc(); }
private:
    internal::scc_graph internal;
};

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
        vector<int> a(m), b(m);
        rep(i, m) {
            cin >> a[i] >> b[i];
            a[i]--; b[i]--;
        }
        UnionFind ds(n);
        rep(i, m) ds.unite(a[i], b[i]);
        scc_graph g(n);
        rep(i, m) g.add_edge(a[i], b[i]);
        auto glst = g.scc();
        unordered_map<int, int> gcnt;
        unordered_set<int> fin;
        for (auto vi : glst) {
            int gid = ds.find(vi.front());
            if (fin.find(gid) != fin.end()) continue;
            if (gcnt[gid]+(int)(vi.size()) <= k) gcnt[gid] += vi.size();
            else fin.insert(gid);
        }
        int res = n;
        for (auto pi : gcnt) res -= pi.second;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
