#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番で作成、WA

int main(){
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
        rep(i, n) rep(j, n) cin >> a[i][j];
        rep(i, n) rep(j, n) cin >> b[i][j];
        vector<int> r(n), c(n);
        rep(i, n) cin >> r[i];
        rep(i, n) cin >> c[i];
        vector<set<int>> rcnt(n), ccnt(n);
        map<int, set<pair<int, int>>> blst;
        rep(i, n) rep(j, n) if (a[i][j] == -1) {
            blst[b[i][j]].emplace(i,j);
            rcnt[i].insert(j); ccnt[j].insert(i);
        }
        while (1) {
            bool operated = false;
            rep(i, n) if ((int)(rcnt[i].size()) == 1) {
                operated = true;
                int ri = i, ci = *rcnt[i].begin();
                rcnt[i].clear();
                ccnt[ci].erase(ri);
                blst[b[ri][ci]].erase({ri,ci});
                if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
            }
            rep(i, n) if ((int)(ccnt[i].size()) == 1) {
                operated = true;
                int ci = i, ri = *ccnt[i].begin();
                ccnt[i].clear();
                rcnt[ri].erase(ci);
                blst[b[ri][ci]].erase({ri,ci});
                if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
            }
            if (!operated) break;
        }
        ll ans = 0;
        while (!blst.empty()) {
            ans += blst.begin()->first;
            auto vrc = *blst.begin()->second.begin();
            blst.begin()->second.erase(blst.begin()->second.begin());
            if (blst.begin()->second.empty()) blst.erase(blst.begin());
            int ri = vrc.first, ci = vrc.second;
            rcnt[ri].erase(ci);
            ccnt[ci].erase(ri);
            if ((int)(rcnt[ri].size())<=1 || (int)(ccnt[ci].size())<=1) {
                while (1) {
                    bool operated = false;
                    rep(i, n) if ((int)(rcnt[i].size()) == 1) {
                        operated = true;
                        int ri = i, ci = *rcnt[i].begin();
                        rcnt[i].clear();
                        ccnt[ci].erase(ri);
                        blst[b[ri][ci]].erase({ri,ci});
                        if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
                    }
                    rep(i, n) if ((int)(ccnt[i].size()) == 1) {
                        operated = true;
                        int ci = i, ri = *ccnt[i].begin();
                        ccnt[i].clear();
                        rcnt[ri].erase(ci);
                        blst[b[ri][ci]].erase({ri,ci});
                        if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
                    }
                    if (!operated) break;
                }
            }
        }
        cout << "Case #" << i1 << ": " << ans << endl;
    }
    return 0;
}
