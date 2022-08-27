#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const int INF = (int)(1e9);

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        vector<string> ab(k);
        rep(i, k) cin >> ab[i];
        int res = INF;
        set<char> scheck;
        for (char ci : s) scheck.insert(ci);
        rep(i, k) for (char ci : ab[i]) scheck.insert(ci);
        unordered_map<char, int> cid;
        for (char ci : scheck) cid[ci] = (int)(cid.size());
        int m = cid.size();
        vector<vector<int>> g(m);
        rep(i, k) g[cid[ab[i][0]]].push_back(cid[ab[i][1]]);
        vector<vector<int>> dist(m, vector<int>(m, INF));
        rep(i, m) dist[i][i] = 0;
        rep(i, m) for (int j : g[i]) dist[i][j] = 1;
        rep(i2, m) rep(i, m) rep(j, m) {
            dist[i][j] = min(dist[i][j], min(INF, dist[i][i2]+dist[i2][j]));
        }
        vector<int> scnt(m);
        for (char ci : s) scnt[cid[ci]]++;
        rep(i2, m) {
            bool ok = true;
            int di = 0;
            rep(i, m) if (i!=i2 && scnt[i]>0) {
                if (dist[i][i2] == INF) {
                    ok = false;
                    break;
                }
                di += dist[i][i2] * scnt[i];
            }
            if (ok) res = min(res, di);
        }
        if (res == INF) res = -1;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
