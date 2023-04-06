// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);
const string ops = "+-*/";
const vector<int> di = { 1, 0, 0, -1 }, dj = { 0, -1, 1, 0 };

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, p, m, ar, ac;
        cin >> n >> p >> m >> ar >> ac;
        --ar; --ac;
        vector<char> op(4);
        vector<int> k(4), x(p), y(p), c(p);
        rep(i, 4) cin >> op[i] >> k[i];
        rep(i, p) {
            cin >> x[i] >> y[i] >> c[i];
            x[i]--; y[i]--;
        }
        vector<vector<vector<vector<ll>>>> dp(n, vector<vector<vector<ll>>>(n, vector<vector<ll>>(m+1, vector<ll>(1<<p, -LINF))));
        dp[ar][ac][0][0] = 0;
        auto calc = [&](ll val, int id) -> ll {
            int pid = ops.find(op[id]);
            if (pid == 0) return val + k[id];
            else if (pid == 1) return val - k[id];
            else if (pid == 2) return val * k[id];
            else {
                if (val >= 0) return val / k[id];
                else return -(((-val)+k[id]-1)/k[id]);
            }
        };
        rep3(i, 1, m+1) rep(j, 1<<p) rep(ii, n) rep(jj, n) {
            int tid = -1;
            rep(j2, p) if (x[j2]==ii && y[j2]==jj) tid = j2;
            rep(i2, 4) {
                int ni = ii + di[i2], nj = jj + dj[i2];
                if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
                if (dp[ni][nj][i-1][j] != -LINF) 
                    dp[ii][jj][i][j] = max(dp[ii][jj][i][j], calc(dp[ni][nj][i-1][j], i2));
                if (tid!=-1 && ((j>>tid)&1) && dp[ni][nj][i-1][j^(1<<tid)]!=-LINF) 
                    dp[ii][jj][i][j] = max(dp[ii][jj][i][j], calc(dp[ni][nj][i-1][j^(1<<tid)],i2)+c[tid]);
            }
            if (dp[ii][jj][i-1][j] != -LINF) 
                dp[ii][jj][i][j] = max(dp[ii][jj][i][j], dp[ii][jj][i-1][j]);
            if (tid!=-1 && ((j>>tid)&1) && dp[ii][jj][i-1][j^(1<<tid)]!=-LINF) 
                dp[ii][jj][i][j] = max(dp[ii][jj][i][j], dp[ii][jj][i-1][j^(1<<tid)]+c[tid]);
        }
        ll res = -LINF;
        rep(i, n) rep(j, n) res = max(res, dp[i][j][m][(1<<p)-1]);
        cout << "Case #" << i0 << ": ";
        if (res == -LINF) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
    }
    return 0;
}
