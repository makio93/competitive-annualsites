// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m;
        cin >> n;
        vector<int> s(n);
        rep(i, n) {
            cin >> s[i];
            s[i]--;
        }
        cin >> m;
        vector<int> k(m);
        rep(i, m) {
            cin >> k[i];
            k[i]--;
        }
        unordered_map<int, set<int>> kids;
        rep(i, m) kids[k[i]].insert(i);
        map<int, ll> dp;
        for (int id : kids[s[0]]) dp[id] = 0;
        rep3(i, 1, n) {
            map<int, ll> ndp;
            for (auto pi : dp) {
                auto litr = kids[s[i]].upper_bound(pi.first);
                if (litr != kids[s[i]].begin()) {
                    --litr;
                    int li = *litr;
                    ll di = pi.second + abs(li-pi.first);
                    if (ndp.find(li) == ndp.end()) ndp[li] = di;
                    else ndp[li] = min(ndp[li], di);
                }
                auto ritr = kids[s[i]].lower_bound(pi.first);
                if (ritr != kids[s[i]].end()) {
                    int ri = *ritr;
                    ll di = pi.second + abs(ri-pi.first);
                    if (ndp.find(ri) == ndp.end()) ndp[ri] = di;
                    else ndp[ri] = min(ndp[ri], di);
                }
            }
            swap(ndp, dp);
        }
        ll res = LINF;
        for (auto pi : dp) res = min(res, pi.second);
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
