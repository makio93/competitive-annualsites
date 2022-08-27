#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// あらためての復習、解説を見てから実装、Test Set 2 までの解答、少し修正

const ll tpd = 12LL * (ll)(1e10); // degree * tpd == ticks (angle)
const ll lt = 360LL * tpd; // 1 lap ticks (angle)
const vector<int> mul = { 1, 12, 720 }; // ticks * mul[i] == time (ns)
const vector<int> deg = { 30, 6, 6 }; // degrees per 1h, 1m, 1s
const vector<ll> ns = { 3600LL*(ll)(1e9), 60LL*(ll)(1e9), (ll)(1e9) };

int main() {
    map<vector<ll>, vector<ll>> hdict;
    rep(h, 12) rep(m, 60) rep(s, 60) {
        ll nstime = h * ns[0] + m * ns[1] + s * ns[2];
        vector<ll> hand = { nstime, nstime*mul[1]%lt, nstime*mul[2]%lt };
        vector<vector<ll>> hlst;
        rep(i, 3) {
            auto hand2 = hand;
            rep(j, 3) if (j != i) hand2[j] = (hand2[j] - hand2[i] + lt) % lt;
            hand2[i] -= hand2[i];
            sort(all(hand2));
            hlst.push_back(hand2);
        }
        sort(all(hlst));
        if (hdict.find(hlst.front()) == hdict.end()) hdict[hlst.front()] = { h, m, s };
    }
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        vector<ll> h(3);
        rep(i, 3) cin >> h[i];
        // Set 1
        vector<int> perm(3);
        rep(i, 3) perm[i] = i;
        vector<vector<ll>> rlst;
        do {
            ll mh = h[perm[0]] * mul[1] % lt, sh = h[perm[0]] * mul[2] % lt;
            if (h[perm[1]]==mh && h[perm[2]]==sh) {
                rlst.push_back(vector<ll>({h[perm[0]]/(ll)(deg[0]*tpd), h[perm[1]]/(ll)(deg[1]*tpd), h[perm[2]]/(ll)(deg[2]*tpd), 0LL}));
            }
        } while (next_permutation(all(perm)));
        if (!rlst.empty()) {
            sort(all(rlst));
            cout << "Case #" << i1 << ": ";
            rep(i, 4) printf("%lld%c", rlst.front()[i], (i<3?' ':'\n'));
            continue;
        }
        // Set 2
        vector<vector<ll>> hlst;
        rep(i, 3) {
            auto h2 = h;
            rep(j, 3) if (j != i) h2[j] = (h2[j] - h2[i] + lt) % lt;
            h2[i] -= h2[i];
            sort(all(h2));
            hlst.push_back(h2);
        }
        sort(all(hlst));
        if (hdict.find(hlst.front()) != hdict.end()) {
            vector<ll> res = hdict[hlst.front()];
            res.push_back(0LL);
            cout << "Case #" << i1 << ": ";
            rep(j, 4) printf("%lld%c", res[j], (j<3?' ':'\n'));
            continue;
        }
        // Set 3 is not available yet.
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
