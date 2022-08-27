// 終了後1,WA

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
        rep(i, (int)(5e6)+1) {
            if (ssum+(ll)i*i == (esum+i)*(esum+i)) {
                res.push_back(i);
                break;
            }
            if (ssum+(ll)i*i == (esum-i)*(esum-i)) {
                res.push_back(-i);
                break;
            }
        }
        if (res.empty()) cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        else cout << "Case #" << i0 << ": " << res[0] << endl;
    }
    return 0;
}
