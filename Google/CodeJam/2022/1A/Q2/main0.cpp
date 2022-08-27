// 終了後,自力AC

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
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<ll> a, a1, a2, b(n);
        rep(i, 30) a1.push_back(1LL<<i);
        rep3(i, 1, 35+1) {
            a2.push_back(1LL+((ll)i<<1)+(1LL<<29));
            a2.push_back(1LL+((((ll)~i)<<1)&((1LL<<29)-1)));
        }
        for (ll aval : a1) a.push_back(aval);
        for (ll aval : a2) a.push_back(aval);
        ll asum = 0;
        rep(i, n) asum += a[i];
        rep(i, n-1) cout << a[i] << ' ';
        cout << a[n-1] << endl;
        rep(i, n) cin >> b[i];
        sort(all(b));
        ll tar = 0, bsum = 0;
        rep(i, n) tar += a[i];
        rep(i, n) tar += b[i];
        tar /= 2;
        rep(i, n) bsum += b[i];
        vector<ll> res;
        int bid = 0;
        while (tar > asum) {
            tar -= b[bid];
            res.push_back(b[bid]);
            ++bid;
        }
        rep(i, 30) if ((tar>>i)&1LL) res.push_back(a1[i]);
        int aid = 0;
        rep3(i, 30, 36) if ((tar>>i)&1LL) {
            int bcnt = 2;
            rep(j, i-30) bcnt *= 2;
            for (int j=aid; j<aid+bcnt; ++j) res.push_back(a2[j]);
            aid += bcnt;
        }
        int m = res.size();
        rep(i, m-1) cout << res[i] << ' ';
        cout << res[m-1] << endl;
    }
    return 0;
}
