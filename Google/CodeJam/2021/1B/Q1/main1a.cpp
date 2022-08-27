#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// あらためての復習、解説を見てから実装、Test Set 1 までの解答、AC

const ll tpd = 12LL * (ll)(1e10); // degree * tpd == ticks (angle)
const ll ldeg = 360LL * tpd; // 1 lap ticks (angle)
const vector<int> mul = { 1, 12, 720 }; // ticks * mul[i] == time (ns)
const vector<int> deg = { 30, 6, 6 }; // degrees per 1h, 1m, 1s

int main() {
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        vector<ll> h(3);
        rep(i, 3) cin >> h[i];
        vector<int> perm(3);
        rep(i, 3) perm[i] = i;
        vector<ll> res;
        do {
            ll tval1 = h[perm[0]] * mul[0];
            ll hours = tval1 / (deg[0]*tpd), minites = tval1 / (deg[1]*tpd);
            ll tval2 = tval1 % (deg[0]*tpd) * mul[1], tval3 = tval2 % (deg[1]*tpd) * (mul[2]/mul[1]);
            if (tval2==h[perm[1]] && tval3==h[perm[2]]) {
                res = vector<ll>({ hours, tval2/(deg[1]*tpd), tval3/(deg[2]*tpd), tval1%(ll)(1e9) });
                break;
            }
        } while (next_permutation(all(perm)));
        cout << "Case #" << i1 << ": ";
        if (!res.empty()) rep(i, 4) printf("%lld%c", res[i], (i<3?' ':'\n'));
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
