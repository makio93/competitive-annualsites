// 本番AC

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
        int n, l;
        cin >> n >> l;
        vector<pair<int, int>> lp, rp;
        rep(i, n) {
            int pi, di;
            cin >> pi >> di;
            if (di == 0) lp.emplace_back(pi, i);
            else rp.emplace_back(pi, i);
        }
        if (!lp.empty()) sort(all(lp));
        if (!rp.empty()) sort(all(rp));
        int llen = lp.size();
        if (!rp.empty()) {
            rep(i, llen) {
                int rid = lower_bound(all(rp), make_pair(lp[i].first, -1)) - rp.begin();
                repr(j, rid) swap(lp[i].second, rp[j].second);
            }
        }
        vector<pair<int, int>> res;
        if (!lp.empty()) {
            for (auto pi : lp) res.emplace_back(pi.first, pi.second+1);
        }
        if (!rp.empty()) {
            for (auto pi : rp) res.emplace_back(l-pi.first, pi.second+1);
        }
        sort(all(res));
        cout << "Case #" << i0 << ": ";
        rep(i, n) printf("%d%c", res[i].second, (i<n-1?' ':'\n'));
    }
    return 0;
}
