// 解説AC1-0(ACLソース使用)

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

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(m), b(m);
        vector<vector<int>> btoa(n);
        rep(i, m) {
            cin >> a[i] >> b[i];
            a[i]--, b[i]--;
            btoa[b[i]].push_back(a[i]);
        }
        scc_graph g(n);
        rep(i, m) g.add_edge(a[i], b[i]);
        auto glst = g.scc();
        unordered_set<int> sst;
        for (auto& vlst : glst) {
            if ((int)(vlst.size()) > k) continue;
            unordered_set<int> checked;
            queue<int> que;
            for (int vi : vlst) {
                que.push(vi);
                checked.insert(vi);
            }
            while (!que.empty() && (int)(checked.size())<=k) {
                int vi = que.front(); que.pop();
                for (int ti : btoa[vi]) if (checked.find(ti) == checked.end()) {
                    que.push(ti);
                    checked.insert(ti);
                    if ((int)(checked.size()) > k) break;
                }
            }
            if ((int)(checked.size()) <= k) for (int vi : checked) sst.insert(vi);
        }
        cout << "Case #" << i0 << ": " << (n-(int)(sst.size())) << endl;
    }
    return 0;
}
