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
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        vector<int> res(n);
        vector<ll> vcnt(n+2, -1);
        vcnt[0] = 0;
        vcnt[n+1] = (ll)n * (n+1) / 2;
        int nval = 1;
        rep(i, n) {
            if (c[i] >= nval) {
                vcnt[nval]++;
                vcnt[min(n,c[i])+1]--;
            }
            if (vcnt[nval] >= 0) {
                vcnt[nval+1] += vcnt[nval];
                ++nval;
            }
            res[i] = nval - 1;
        }
        cout << "Case #" << i0 << ":";
        rep(i, n) cout << ' ' << res[i];
        cout << endl;
    }
    return 0;
}
