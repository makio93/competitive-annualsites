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
        vector<int> r(n);
        rep(i, n) cin >> r[i];
        vector<pair<int, int>> rlst(n);
        rep(i, n) rlst[i] = { r[i], i };
        sort(all(rlst));
        vector<int> res(n, -1);
        rep(i, n) {
            auto itr = upper_bound(all(rlst), make_pair(r[i]*2, n));
            if (itr == rlst.begin()) continue;
            --itr;
            if (itr->second == i) {
                if (itr == rlst.begin()) continue;
                --itr;
            }
            res[i] = itr->first;
        }
        cout << "Case #" << i0 << ": ";
        rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    }
    return 0;
}
