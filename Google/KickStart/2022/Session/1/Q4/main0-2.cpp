// 本番提出2, Set1:AC, Set2:WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

struct mf_graph {
public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}
    int add_edge(int from, int to, int cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
        return m;
    }
    struct edge {
        int from, to;
        int cap, flow;
    };
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    vector<edge> edges() {
        int m = int(pos.size());
        vector<edge> result;
        for (int i = 0; i < m; i++) result.push_back(get_edge(i));
        return result;
    }
    void change_edge(int i, int new_cap, int new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }
    int flow(int s, int t) { return flow(s, t, numeric_limits<int>::max()); }
    int flow(int s, int t, int flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        vector<int> level(_n), iter(_n);
        queue<int> que;
        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            queue<int>().swap(que);
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, int up) {
            if (v == s) return up;
            int res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                int d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };
        int flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                int f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }
    vector<bool> min_cut(int s) {
        vector<bool> visited(_n);
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
  private:
    int _n;
    struct _edge {
        int to, rev;
        int cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};

const vector<int> di = { -1, -1, 0, 1, 1, 0 }, dj = { 0, 1, 1, 0, -1, -1 };
const vector<char> cols = { 'B', 'R' };
const vector<string> msgs = { "Impossible", "Blue wins", "Red wins", "Nobody wins" };

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        vector<string> board(n);
        rep(i, n) cin >> board[i];
        int res = 3;
        vector<int> ccnts(2), acnts(2);
        rep(i, n) rep(j, n) rep(j2, 2) if (board[i][j] == cols[j2]) ccnts[j2]++;
        if (abs(ccnts[0]-ccnts[1]) >= 2) res = 0;
        if (res != 0) {
            const vector<vector<int>> di = { { -1, 0 }, { 1, 1 } }, dj = { { 1, 1 }, { -1, 0 } };
            const vector<int> prei = { -1, 0 }, prej = { 0, -1 };
            rep(i1, 2) {
                int tid = (ccnts[i1]>=ccnts[1-i1]) ? 1 : 0;
                mf_graph g(2*n*n+2);
                rep(i, n) rep(j, n) if (board[i][j] == cols[i1]) {
                    g.add_edge(i*n+j, i*n+j+n*n, 1);
                    if (i1 == 0) {
                        if (j == 0) g.add_edge(2*n*n, i*n+j, 1);
                        if (j == n-1) g.add_edge(i*n+j+n*n, 2*n*n+1, 1);
                    }
                    else {
                    if (i == 0) g.add_edge(2*n*n, i*n+j, 1);
                    if (i == n-1) g.add_edge(i*n+j+n*n, 2*n*n+1, 1);
                    }
                    rep(i2, 2) {
                        int ni = i + di[i1][i2], nj = j + dj[i1][i2];
                        if (ni<0 || ni>=n || nj<0 || nj>=n || board[ni][nj]!=cols[i1]) continue;
                        g.add_edge(i*n+j+n*n, ni*n+nj, 1);
                    }
                    int ni2 = i + prei[i1], nj2 = j + prej[i1];
                    if (ni2>=0 && ni2<n && nj2>=0 && nj2<n && board[ni2][nj2]==cols[i1]) {
                        g.add_edge(i*n+j+n*n, ni2*n+nj2, 1);
                        g.add_edge(ni2*n+nj2+n*n, i*n+j, 1);
                    }
                }
                int kval = g.flow(2*n*n, 2*n*n+1, n);
                acnts[tid] += kval;
                if (kval == 1) res = i1 + 1;
            }
        }
        if (acnts[0]>0 || acnts[1]>1) res = 0;
        cout << "Case #" << i0 << ": " << msgs[res] << endl;
    }
    return 0;
}
