// 自力AC

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
        string p;
        cin >> n >> p;
        int mval = n;
        auto check = [&](int li, int ri) -> bool {
            while (li < ri) {
                if (p[li] != p[ri]) return false;
                ++li; --ri;
            }
            return true;
        };
        rep3r(i, 1, n)  if (n%i == 0) {
            if (!check(0, i-1)) continue;
            bool ok = true;
            for (int li=i; li<n; li+=i) if (p.substr(li-i, i) != p.substr(li, i)) {
                ok = false;
                break;
            }
            if (ok) mval = min(mval, i);
        }
        cout << "Case #" << i0 << ": " << p.substr(0, mval) << endl;
    }
    return 0;
}
