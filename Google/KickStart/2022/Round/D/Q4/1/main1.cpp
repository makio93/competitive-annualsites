// 学習1回目,解説AC

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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n), rg(n);
        rep(i, m) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[ai].push_back(bi);
            rg[bi].push_back(ai);
        }
        vector<int> vs, cmp(n, -1);
        vector<bool> visited(n);
        auto dfs1 = [&](auto dfs1, int vi) -> void {
            visited[vi] = true;
            for (const int& ti : g[vi]) if (!visited[ti]) dfs1(dfs1, ti);
            vs.push_back(vi);
        };
        rep(i, n) if (!visited[i]) dfs1(dfs1, i);
        auto dfs2 = [&](auto dfs2, int vi, int cid) -> void {
            cmp[vi] = cid;
            for (const int& ti : rg[vi]) if (cmp[ti] == -1) dfs2(dfs2, ti, cid);
        };
        int sid = 0;
        repr(i, n) if (cmp[vs[i]] == -1) {
            dfs2(dfs2, vs[i], sid);
            ++sid;
        }
        vector<unordered_set<int>> sg(sid);
        rep(i, n) for (const int& ti : g[i]) if (cmp[i] != cmp[ti]) sg[cmp[i]].insert(cmp[ti]);
        vector<int> slst(sid);
        rep(i, n) slst[cmp[i]]++;
        vector<unordered_set<int>> checks(sid);
        vector<int> ccnt(sid);
        rep(i, sid) checks[i].insert(i);
        rep(i, sid) ccnt[i] = slst[i];
        int res = 0;
        rep(i, sid) {
            if (ccnt[i] > k) res += slst[i];
            for (const int& ti : sg[i]) {
                for (const int& ci : checks[i]) {
                    if (ccnt[ti] > k) break;
                    if (checks[ti].find(ci) == checks[ti].end()) {
                        checks[ti].insert(ci);
                        ccnt[ti] += slst[ci];
                    }
                }
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
