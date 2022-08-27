#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番未提出

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int r, c, k;
        cin >> r >> c >> k;
        --k;
        vector<string> g(r);
        rep(i, r) cin >> g[i];
        vector<int> usum(c), dsum(c);
        rep(i, c) {
            for (int j=k; j>=0; --j) if (g[j][i] == '.') usum[i]++;
            for (int j=k; j<r; ++j) if (g[j][i] == '.') dsum[i]++;
        }
        int res = (int)(1e9);
        vector<int> bcnt(c);
        for (int i=k; i<r; ++i) {
            rep(j, c) if (g[i][j] == 'X') bcnt[j]++;
            int val = abs(k-i);
            rep(j, c) {
                if (bcnt[j] <= usum[j]) { if (g[i][j] == 'X') ++val; }
                else ++val;
            }
            res = min(res, val);
        }
        {
            int val = abs(r-k);
            rep(j, c) if (bcnt[j] > usum[j]) ++val;
            res = min(res, val);
        }
        bcnt = vector<int>(c);
        for (int i=k; i>=0; --i) {
            rep(j, c) if (g[i][j] == 'X') bcnt[j]++;
            int val = abs(k-i);
            rep(j, c) {
                if (bcnt[j] <= dsum[j]) { if (g[i][j] == 'X') ++val; }
                else ++val;
            }
            res = min(res, val);
        }
        {
            int val = abs(-1-k);
            rep(j, c) if (bcnt[j] > dsum[j]) ++val;
            res = min(res, val);
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
