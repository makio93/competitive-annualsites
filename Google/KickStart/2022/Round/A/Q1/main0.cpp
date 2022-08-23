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
        string I, P;
        cin >> I >> P;
        int n = I.length(), m = P.length();
        int id = 0;
        bool ok = true;
        int res = 0;
        rep(i, n) {
            while (id<m && P[id]!=I[i]) {
                ++id;
                ++res;
            }
            if (id >= m) {
                ok = false;
                break;
            }
            ++id;
        }
        if (ok) res += m - id;
        cout << "Case #" << i0 << ": ";
        if (ok) cout << res << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
