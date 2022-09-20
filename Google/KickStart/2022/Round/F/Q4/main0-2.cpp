// 自力AC

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
        int n, k, x, d, m;
        cin >> n >> k >> x >> d >> m;
        vector<int> p(m), l(m), r(m);
        rep(i, m) {
            cin >> p[i] >> l[i] >> r[i];
            p[i]--;
        }
        int sub = n - k;
        map<int, vector<pair<int, int>>> sche;
        rep(i, m) {
            sche[l[i]].emplace_back(p[i], 1);
            sche[r[i]+x-1].emplace_back(p[i], -1);
        }
        vector<int> pcnt(n);
        set<pair<int, int>> ust, dst;
        int sum = 0, res = INF;
        rep(i, d) {
            if (sche.find(i) != sche.end()) {
                for (auto& pi : sche[i]) {
                    int pid = pi.first, sval = pi.second;
                    pair<int, int> tpi = { pcnt[pid], pid };
                    if (pcnt[pid] != 0) {
                        if (ust.find(tpi) != ust.end()) {
                            ust.erase(tpi);
                            sum -= pcnt[pid];
                        }
                        else {
                            dst.erase(tpi);
                            while (!ust.empty() && (int)(dst.size())<sub) {
                                auto tmp = *ust.rbegin();
                                ust.erase(tmp);
                                sum -= tmp.first;
                                dst.insert(tmp);
                            }
                        }
                    }
                    tpi.first += sval;
                    pcnt[pid] += sval;
                    if (tpi.first != 0) {
                        dst.insert(tpi);
                        while ((int)(dst.size()) > sub) {
                            auto npi = *dst.begin();
                            dst.erase(npi);
                            ust.insert(npi);
                            sum += npi.first;
                        }
                    }
                }
            }
            if (i >= x-1) res = min(res, sum);
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
