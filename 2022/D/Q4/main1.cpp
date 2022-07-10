// 解説AC1

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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n), rg(n);
        rep(i, m) {
            int ai, bi;
            cin >> ai >> bi;
            --ai, --bi;
            g[ai].push_back(bi);
            rg[bi].push_back(ai);
        }
        vector<bool> used(n);
        vector<int> vord;
        auto dfs = [&](auto dfs, int vi) -> void {
            used[vi] = true;
            for (int ti : g[vi]) if (!used[ti]) dfs(dfs, ti);
            vord.push_back(vi);
        };
        rep(i, n) if (!used[i]) dfs(dfs, i);
        used.assign(n, false);
        vector<vector<int>> clst;
        auto rdfs = [&](auto rdfs, int vi) -> void {
            used[vi] = true;
            clst.back().push_back(vi);
            for (int ti : rg[vi]) if (!used[ti]) rdfs(rdfs, ti);
        };
        repr(i, n) if (!used[vord[i]]) {
            clst.push_back(vector<int>(0));
            rdfs(rdfs, vord[i]);
        }
        vector<bool> ins(n, true);
        for (auto vlst : clst) {
            unordered_set<int> tst;
            queue<int> que;
            for (int vi : vlst) {
                tst.insert(vi);
                que.push(vi);
                if ((int)(tst.size()) > k) break;
            }
            while (!que.empty() && (int)(tst.size())<=k) {
                int vi = que.front(); que.pop();
                for (int ti : rg[vi]) if (tst.find(ti) == tst.end()) {
                    tst.insert(ti);
                    que.push(ti);
                    if ((int)(tst.size()) > k) break;
                }
            }
            if ((int)(tst.size()) <= k) for (int vi : tst) ins[vi] = false;
        }
        int res = 0;
        rep(i, n) if (ins[i]) ++res;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
