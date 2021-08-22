#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,Set1までAC

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        int r, c, k;
        cin >> r >> c >> k;
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        ll res = 0;
        int rcnt = 0, ccnt = 0;
        if (r1 == 1) ++rcnt;
        if (r2 == r) ++rcnt;
        if (c1 == 1) ++ccnt;
        if (c2 == c) ++ccnt;
        if (k == 1) {
            res += min({r1-1, r-r2, c1-1, c-c2});
            res += (ll)(r2 - r1 + 1) * (2 - ccnt) + (ll)(c2 - c1 + 1) * (2 - rcnt);
            res += (ll)(r2-r1+1) * (c2-c1) + (ll)(c2-c1+1) * (r2-r1);
        }
        else {
            res = (ll)(1e18);
            rep(i2, 2) {
                ll rval = 0;
                int ldir = i2;
                int fdir = (min(r1-1,r-r2) <= min(c1-1,c-c2)) ? 1 : 0;
                int flen = min({r1-1, r-r2, c1-1, c-c2});
                if (fdir == 1) {
                    if (ccnt == 0) rval += ((ll)(r2-r1+1)+flen + k-1) / k;
                    if (ccnt <= 1) rval += ((ll)(r2-r1+1) + k-1) / k;
                    rval += ((ll)(c2-c1+1)*(2-rcnt) + k-1) / k;
                }
                else {
                    if (rcnt == 0) rval += ((ll)(c2-c1+1)+flen + k-1) / k;
                    if (rcnt <= 1) rval += ((ll)(c2-c1+1) + k-1) / k;
                    rval += ((ll)(r2-r1+1)*(2-ccnt) + k-1) / k;
                }
                if (ldir == 1) {
                    rval += (ll)(((ll)(c2-c1+1)+k-1) / k) * (r2-r1);
                    rval += (ll)(r2-r1+1) * (c2-c1);
                }
                else {
                    rval += (ll)(((ll)(r2-r1+1)+k-1) / k) * (c2-c1);
                    rval += (ll)(c2-c1+1) * (r2-r1);
                }
                res = min(res, rval);
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
