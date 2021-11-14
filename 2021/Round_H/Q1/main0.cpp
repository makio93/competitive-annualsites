#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        string s, f;
        cin >> s >> f;
        int n = s.length(), m = f.length();
        int res = 0;
        rep(i, n) {
            int mval = INF;
            rep(j, m) mval = min({ mval, abs(s[i]-f[j]), 26-abs(s[i]-f[j]) });
            res += mval;
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
