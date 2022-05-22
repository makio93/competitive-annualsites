// 本番,TLE

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
        ll x, y;
        cin >> n >> x >> y;
        ll s = (ll)n * (n+1) / 2;
        if (s*x%(x+y) != 0) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        ll tar = s * x / (x+y);
        vector<vector<int>> dp(n+1, vector<int>(tar+1, -1));
        dp[0][0] = 0;
        rep3(i, 1, n+1) rep(j, tar+1) {
            if (dp[i-1][j] != -1) dp[i][j] = j;
            if (j-i>=0 && dp[i-1][j-i]!=-1) dp[i][j] = j-i;
        }
        if (dp[n][tar] == -1) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        ll val = tar;
        vector<int> res;
        rep3r(i, 1, n+1) {
            if (dp[i][val] != val) res.push_back(i);
            val = dp[i][val];
        }
        sort(all(res));
        cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
        int m = res.size();
        cout << m << endl;
        rep(i, m) printf("%d%c", res[i], (i<m-1?' ':'\n'));
    }
    return 0;
}
