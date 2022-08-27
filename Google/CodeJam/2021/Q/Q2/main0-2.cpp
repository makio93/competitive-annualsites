#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番終了後、自力で実装しなおしてみる、AC

const int INF = (int)(1e9);

int main() {
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(2, INF));
        dp[0][0] = dp[0][1] = 0;
        rep(i, n) {
            if (i == 0) {
                if (s[i] == 'C') dp[i+1][0] = 0;
                else if (s[i] == 'J') dp[i+1][1] = 0;
                else dp[i+1][0] = dp[i+1][1] = 0;
            }
            else {
                if (s[i] == 'C') {
                    rep(j, 2) if (dp[i][j] < INF) {
                        if (j == 1) dp[i+1][0] = min(dp[i+1][0], dp[i][j]+y);
                        else dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
                    }
                }
                else if (s[i] == 'J') {
                    rep(j, 2) if (dp[i][j] < INF) {
                        if (j == 0) dp[i+1][1] = min(dp[i+1][1], dp[i][j]+x);
                        else dp[i+1][1] = min(dp[i+1][1], dp[i][j]);
                    }
                }
                else {
                    rep(j, 2) if (dp[i][j] < INF) {
                        if (j == 0) dp[i+1][1-j] = min(dp[i+1][1-j], dp[i][j]+x);
                        else dp[i+1][1-j] = min(dp[i+1][1-j], dp[i][j]+y);
                        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                    }
                }
            }
        }
        int res = min(dp[n][0], dp[n][1]);
        cout << "Case #" << i1 << ": " << res << endl;
    }
    return 0;
}
