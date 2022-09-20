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
        int n;
        cin >> n;
        vector<string> c(n);
        vector<int> d(n), u(n);
        rep(i, n) cin >> c[i] >> d[i] >> u[i];
        vector<int> aord(n), bord(n);
        iota(all(aord), 0);
        iota(all(bord), 0);
        sort(all(aord), [&](int li, int ri) -> bool {
            return make_pair(c[li], u[li]) < make_pair(c[ri], u[ri]);
        });
        sort(all(bord), [&](int li, int ri) -> bool {
            return make_pair(d[li], u[li]) < make_pair(d[ri], u[ri]);
        });
        int res = 0;
        rep(i, n) if (aord[i] == bord[i]) ++res;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
