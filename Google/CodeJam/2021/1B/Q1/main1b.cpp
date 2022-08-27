#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// あらためての復習、解説を見てから実装、Test Set 2 までの解答、AC

const ll tpd = 12LL * (ll)(1e10); // degree * tpd == ticks (angle)
const ll lt = 360LL * tpd; // 1 lap ticks (angle)
const vector<int> mul = { 1, 12, 720 }; // ticks * mul[i] == time (ns)
const vector<int> deg = { 30, 6, 6 }; // degrees per 1h, 1m, 1s
const vector<ll> ns = { 3600LL*(ll)(1e9), 60LL*(ll)(1e9), (ll)(1e9) };

int main() {
    int t;
    cin >> t;
    map<vector<ll>, vector<ll>> hdict;
    rep(h, 12) rep(m, 60) rep(s, 60) {
        ll nstime = h * ns[0] + m * ns[1] + s * ns[2];
        vector<ll> hand = { nstime, nstime*mul[1]%lt, nstime*mul[2]%lt };
        auto hand2 = hand;
        sort(all(hand2));
        repr(j, 3) hand2[j] -= hand2.front();
        if (hdict.find(hand2) != hdict.end()) hdict[hand2] = min(hdict[hand2], {h,m,s});
        else hdict[hand2] = { h, m, s };
    }
    rep3(i1, 1, t+1) {
        vector<ll> h(3);
        rep(i, 3) cin >> h[i];
        // Set 1
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
        if (!res.empty()) {
            cout << "Case #" << i1 << ": ";
            rep(i, 4) printf("%lld%c", res[i], (i<3?' ':'\n'));
            continue;
        }
        // Set 2
        rep(i, 3) perm[i] = i;
        vector<vector<ll>> tval;
        rep(i, (1<<3)) {
            auto h2 = h;
            rep(j, 3) if ((i>>j)&1) h2[j] += lt;
            sort(all(h2));
            repr(j, 3) h2[j] -= h2.front();
            if (hdict.find(h2) != hdict.end()) tval.push_back(vector<ll>({hdict[h2][0], hdict[h2][1], hdict[h2][2], 0LL}));
        }
        if (!tval.empty()) {
            sort(all(tval));
            res = tval.front();
            cout << "Case #" << i1 << ": ";
            rep(j, 4) printf("%lld%c", res[j], (j<3?' ':'\n'));
            continue;
        }
    }
    return 0;
}
