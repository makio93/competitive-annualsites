// 本番2,WA

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
        if (k > 1) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        ll ssum = 0, esum = 0;
        rep(i, n) ssum += ei[i] * ei[i];
        rep(i, n) esum += ei[i];
        vector<ll> res;
        if (ssum == esum*esum) res.push_back(0);
        else {
            if (ssum > esum*esum) {
                if (esum >= 0) {
                    ll dval = 1;
                    int cnt = 0;
                    while (ssum+dval*dval > (esum+dval)*(esum+dval) && cnt<(int)(1e3)) {
                        ++dval;
                        ++cnt;
                    }
                    if (ssum+dval*dval == (esum+dval)*(esum+dval)) {
                        res.push_back(dval);
                    }
                    else {
                        cnt = 0;
                        dval = 1;
                        while (ssum+dval*dval > (esum-dval)*(esum-dval) && cnt<(int)(1e3)) ++dval, ++cnt;
                        if (ssum+dval*dval == (esum-dval)*(esum-dval)) {
                            res.push_back(-dval);
                        }
                    }
                }
                else {
                    ll dval = 1;
                    int cnt = 0;
                    while (ssum+dval*dval > (esum-dval)*(esum-dval) && cnt<(int)(1e3)) ++dval, ++cnt;
                    if (ssum+dval*dval == (esum-dval)*(esum-dval)) {
                        res.push_back(-dval);
                    }
                    else {
                        dval = 1;
                        cnt = 0;
                        while (ssum+dval*dval > (esum+dval)*(esum+dval) && cnt<(int)(1e3)) ++dval, ++cnt;
                        if (ssum+dval*dval == (esum+dval)*(esum+dval)) {
                            res.push_back(dval);
                        }
                    }
                }
            }
            else {
                if (esum >= 0) {
                    ll dval = 1;
                    int cnt = 0;
                    while (ssum+dval*dval < (esum-dval)*(esum-dval) && cnt<(int)(1e3)) ++dval;
                    if (ssum+dval*dval == (esum-dval)*(esum-dval)) {
                        res.push_back(-dval);
                    }
                    else {
                        dval = 1;
                        cnt = 0;
                        while (ssum+dval*dval < (esum+dval)*(esum+dval) && cnt<(int)(1e3)) ++dval, ++cnt;
                        if (ssum+dval*dval == (esum+dval)*(esum+dval)) {
                            res.push_back(dval);
                        }
                    }
                }
                else {
                    ll dval = 1;
                    int cnt = 0;
                    while (ssum+dval*dval < (esum+dval)*(esum+dval) && cnt<(int)(1e3)) ++cnt, ++dval;
                    if (ssum+dval*dval == (esum+dval)*(esum+dval)) {
                        res.push_back(dval);
                    }
                    else {
                        dval = 1;
                        cnt = 0;
                        while (ssum+dval*dval < (esum-dval)*(esum-dval) && cnt<(int)(1e3)) ++dval, ++cnt;
                        if (ssum+dval*dval == (esum-dval)*(esum-dval)) {
                            res.push_back(-dval);
                        }
                    }
                }
            }
        }
        if (res.empty()) cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        else cout << "Case #" << i0 << ": " << res[0] << endl;
    }
    return 0;
}
