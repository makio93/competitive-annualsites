// 解説2,AC

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
        vector<ll> prea(n+1), sufa(n+1), preb(m+1), sufb(m+1), pa(k+1), pb(k+1);
        rep(i, n) prea[i+1] = prea[i] + a[i];
        rep(i, n) sufa[i+1] = sufa[i] + a[n-i-1];
        rep(i, m) preb[i+1] = preb[i] + b[i];
        rep(i, m) sufb[i+1] = sufb[i] + b[m-i-1];
        rep(i, n+1) for (int j=0; i+j<=min(n,k); ++j) pa[i+j] = max(pa[i+j], prea[i]+sufa[j]);
        rep(i, m+1) for (int j=0; i+j<=min(m,k); ++j) pb[i+j] = max(pb[i+j], preb[i]+sufb[j]);
        ll res = 0;
        rep(i, k+1) res = max(res, pa[i]+pb[k-i]);
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
