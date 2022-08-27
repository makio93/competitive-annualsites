#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中に実装、Set1までAC

int main() {
    int t;
    cin >> t;
    ll rbase = 360LL * 12LL * (ll)(1e10);
    ll hbase = 30LL * 12LL * (ll)(1e10);
    ll mbase = 6LL * 12LL * (ll)(1e10);
    ll sbase = 6LL * 12LL * (ll)(1e10);
    vector<ll> bases = { hbase, mbase, sbase, 1 };
    vector<ll> secbase = { (ll)(1e9), (ll)(1e9)*12LL, (ll)(1e9)*720LL };
    rep3(i1, 1, t+1) {
        vector<ll> hands1(3);
        rep(i, 3) cin >> hands1[i];
        vector<ll> res(4);
        rep(i2, 60) {
            bool ok = false;
            auto hands = hands1;
            rep(i, 3) hands[i] = (hands[i] + sbase * i2) % rbase;
            rep(i, 3) {
                ll sub = hands[i] - hands[i] / secbase[0] * secbase[0];
                ll hi = hands[i] - sub, mi = hi * 12LL % rbase, si = mi * 60LL % rbase;
                if ((mi==(hands[(i+1)%3]-sub+rbase)%rbase&&si==(hands[(i+2)%3]-sub+rbase)%rbase) || (mi==(hands[(i+2)%3]-sub+rbase)%rbase&&si==(hands[(i+1)%3]-sub+rbase)%rbase)) {
                    res = { hi, mi, si, 0LL };
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        cout << "Case #" << i1 << ": ";
        rep(i, 4) printf("%lld%c", res[i]/bases[i], (i<3?' ':'\n'));
    }
    return 0;
}
