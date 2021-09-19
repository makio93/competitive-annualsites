#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int d, n, k;
        cin >> d >> n >> k;
        vector<int> h(n), s(n), e(n);
        rep(i, n) {
            cin >> h[i] >> s[i] >> e[i];
            s[i]--; e[i]--;
        }
        vector<vector<int>> ds(d), de(d);
        rep(i, n) ds[s[i]].push_back(h[i]);
        rep(i, n) de[e[i]].push_back(h[i]);
        set<pair<int, int>> holds;
        unordered_map<int, int> hcnt;
        pair<int, int> tval = { -1, 0 };
        ll val = 0, res = 0;
        rep(i, d) {
            if (!ds[i].empty()) {
                for (int vi : ds[i]) {
                    hcnt[vi]++;
                    pair<int, int> nval = make_pair(vi, -hcnt[vi]);
                    if (tval.second == 0) {
                        holds.insert(nval);
                        if ((int)(holds.size()) == k) tval = *holds.begin();
                        val += nval.first;
                    }
                    else {
                        if (nval > tval) {
                            val -= tval.first;
                            val += nval.first;
                            holds.insert(nval);
                            tval = *next(holds.lower_bound(tval));
                        }
                        else holds.insert(nval);
                    }
                }
            }
            res = max(res, val);
            if (!de[i].empty()) {
                for (int vi : de[i]) {
                    pair<int, int> nval = make_pair(vi, -hcnt[vi]);
                    hcnt[vi]--;
                    if (tval.second == 0) {
                        holds.erase(nval);
                        val -= nval.first;
                    }
                    else {
                        if (nval >= tval) {
                            if ((int)(holds.size()) == k) tval = { -1, 0 };
                            else tval = *prev(holds.lower_bound(tval));
                            val -= nval.first;
                            holds.erase(nval);
                            if (tval.second != 0) val += tval.first;
                        }
                        else holds.erase(nval);
                    }
                }
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
