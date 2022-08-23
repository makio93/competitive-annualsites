// 本番AC

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
        int n, m, k;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        cin >> m;
        vector<int> b(m);
        rep(i, m) cin >> b[i];
        cin >> k;
        vector<ll> alsum(n+1), arsum(n+1), blsum(m+1), brsum(m+1);
        rep(i, n) alsum[i+1] = alsum[i] + a[i];
        rep(i, n) arsum[i+1] = arsum[i] + a[n-i-1];
        rep(i, m) blsum[i+1] = blsum[i] + b[i];
        rep(i, m) brsum[i+1] = brsum[i] + b[m-i-1];
        vector<ll> akvals(k+1), bkvals(k+1);
        rep(i, n+1) rep(j, n+1) {
            if (i+j>k || i+j>n) break;
            akvals[i+j] = max(akvals[i+j], alsum[i]+arsum[j]);
        }
        rep(i, m+1) rep(j, m+1) {
            if (i+j>k || i+j>m) break;
            bkvals[i+j] = max(bkvals[i+j], blsum[i]+brsum[j]);
        }
        ll res = 0;
        rep(i, k+1) res = max(res, akvals[i]+bkvals[k-i]);
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
