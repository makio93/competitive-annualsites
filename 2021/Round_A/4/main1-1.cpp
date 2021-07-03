#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説を見てから実装、Test Set1までの得点

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
        if (n > 8) {
            cout << "Case #" << i0 << ": " << 0 << endl;
            continue;
        }
        int res = (int)(1e9);
        for (ll i=0; i<(1LL<<(n*n)); ++i) {
            vector<vector<bool>> a2(n, vector<bool>(n));
            int sum = 0;
            rep(j, (n*n)) if ((i>>j) & 1) {
                a2[j/n][j%n] = true;
                sum += b[j/n][j%n];
            }
            rep(i2, n) rep(j2, n) if (!a2[i2][j2] && a[i2][j2]!=-1) a2[i2][j2] = true;
            vector<set<int>> rcnt(n), ccnt(n);
            rep(i2, n) rep(j2, n) if (!a2[i2][j2]) {
                rcnt[i2].insert(j2);
                ccnt[j2].insert(i2);
            }
            queue<pair<int, int>> que;
            rep(i2, n) if ((int)(rcnt[i2].size()) == 1) {
                int ci = (*rcnt[i2].begin());
                que.emplace(i2, ci);
                a2[i2][ci] = true;
                rcnt[i2].clear();
                ccnt[ci].erase(i2);
            }
            rep(i2, n) if ((int)(ccnt[i2].size()) == 1) {
                int ri = (*ccnt[i2].begin());
                que.emplace(ri, i2);
                a2[ri][i2] = true;
                ccnt[i2].clear();
                rcnt[ri].erase(i2);
            }
            while (!que.empty()) {
                auto p = que.front(); que.pop();
                int ri = p.first, ci = p.second;
                if ((int)(rcnt[ri].size()) == 1) {
                    int nci = (*rcnt[ri].begin());
                    que.emplace(ri, nci);
                    a2[ri][nci] = true;
                    rcnt[ri].clear();
                    ccnt[nci].erase(ri);
                }
                if ((int)(ccnt[ci].size()) == 1) {
                    int nri = (*ccnt[ci].begin());
                    que.emplace(nri, ci);
                    a2[nri][ci] = true;
                    ccnt[ci].clear();
                    rcnt[nri].erase(ci);
                }
            }
            bool ok = true;
            rep(i2, n) rep(j2, n) if (!a2[i2][j2]) ok = false;
            if (ok) res = min(res, sum);
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
