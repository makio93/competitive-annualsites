// 本番,WA

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
        int n, k;
        cin >> n >> k;
        vector<ll> ei(n);
        rep(i, n) cin >> ei[i];
        ll esum = 0, ssum = 0;
        rep(i, n) esum += ei[i];
        rep(i, n) ssum += ei[i] * ei[i];
        vector<ll> res, vlst;
        auto dfs = [&](auto dfs, int ki) -> bool {
            if (esum*esum == ssum) {
                res = vlst;
                return true;
            }
            if (ki == 0) return false;
            ll dval = floor(sqrt(abs(ssum-esum*esum)));
            if (abs(dval)>0) {
                if (dval > 0) --dval;
                else ++dval;
            }
            if (esum*esum > ssum) {
                if (abs((abs(esum)-dval-1)*(abs(esum)-dval-1)-(ssum+(dval+1)*(dval+1))) < abs(abs(esum)*abs(esum)-ssum)) {while ((abs(esum)-dval-1)*(abs(esum)-dval-1) > ssum+(dval+1)*(dval+1)) ++dval;}
                if (esum >= 0LL) {
                    ll tei = -dval;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                    --tei;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                }
                else {
                    ll tei = dval;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                    ++tei;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                }
            }
            else {
                if (abs((abs(esum)+dval+1)*(abs(esum)+dval+1)-(ssum+(dval+1)*(dval+1))) < abs(abs(esum)*abs(esum)-ssum)) { while ((abs(esum)+dval+1)*(abs(esum)+dval+1) < ssum+(dval+1)*(dval+1)) ++dval; }
                if (esum < 0LL) {
                    ll tei = -dval;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                    --tei;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                }
                else {
                    ll tei = dval;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                    ++tei;
                    if (abs(tei) <= (ll)(1e18)) {
                        vlst.push_back(tei);
                        esum += tei;
                        ssum += tei * tei;
                        if (dfs(dfs, ki-1)) return true;
                        ssum -= tei * tei;
                        esum -= tei;
                        vlst.pop_back();
                    }
                }
            }
            return false;
        };
        if (dfs(dfs, k)) {
            cout << "Case #" << i0 << ": ";
            if (res.empty()) res.push_back(0);
            int m = res.size();
            rep(i, m-1) printf("%lld ", res[i]);
            cout << res[m-1] << endl;
        }
        else {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
