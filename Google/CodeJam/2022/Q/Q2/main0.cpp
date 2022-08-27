// 本番AC

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
        vector<vector<int>> units(3, vector<int>(4));
        rep(i, 3) rep(j, 4) cin >> units[i][j];
        vector<int> mvals(4, INF);
        rep(i, 3) rep(j, 4) mvals[j] = min(mvals[j], units[i][j]);
        int sum = 0;
        rep(i, 4) sum += mvals[i];
        if (sum < (int)(1e6)) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        rep(i1, 4) {
            int tsum = 0;
            rep(i, 4) tsum += mvals[i];
            if (tsum == (int)(1e6)) break;
            pair<int, int> mid = { -1, -1 };
            rep(i, 4) mid = max(mid, { mvals[i], i });
            int tid = mid.second;
            mvals[tid] -= min(mvals[tid], tsum-(int)(1e6));
        }
        cout << "Case #" << i0 << ": ";
        rep(i, 4) cout << mvals[i] << (i<3 ? ' ' : '\n');
    }
    return 0;
}
