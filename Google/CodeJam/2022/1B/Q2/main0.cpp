// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1.5e9);
const ll LINF = (ll)(1e18);

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, p;
        cin >> n >> p;
        vector<vector<int>> x(n, vector<int>(p));
        rep(i, n) rep(j, p) cin >> x[i][j];
        vector<int> mx(n+1), mn(n+1, INF);
        mx[0] = 0;
        mn[0] = 0;
        rep(i, n) rep(j, p) {
            mx[i+1] = max(mx[i+1], x[i][j]);
            mn[i+1] = min(mn[i+1], x[i][j]);
        }
        vector<vector<ll>> dp(n+1, vector<ll>(2, LINF));
        dp[0][0] = dp[0][1] = 0;
        rep(i, n) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0]+abs((ll)mx[i]-mn[i+1])+abs((ll)mx[i+1]-mn[i+1]));
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]+abs((ll)mn[i]-mn[i+1])+abs((ll)mx[i+1]-mn[i+1]));
            dp[i+1][1] = min(dp[i+1][1], dp[i][0]+abs((ll)mx[i]-mx[i+1])+abs((ll)mx[i+1]-mn[i+1]));
            dp[i+1][1] = min(dp[i+1][1], dp[i][1]+abs((ll)mn[i]-mx[i+1])+abs((ll)mx[i+1]-mn[i+1]));
        }
        ll res = min(dp[n][0], dp[n][1]);
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
