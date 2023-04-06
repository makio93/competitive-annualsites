// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll LINF = (ll)(1e18);

const vector<int> di = { 1, 0, 0, -1 }, dj = { 0, -1, 1, 0 };
const string ops = "+-*/";
ll calc(ll val, char op, int ki) {
    int oid = ops.find(op);
    if (oid == 0) return val + ki;
    else if (oid == 1) return val - ki;
    else if (oid == 2) return val * ki;
    else {
        if (val >= 0) return val / ki;
        else return -((abs(val) + ki - 1) / ki);
    }
}

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, p, m, ar, ac;
        cin >> n >> p >> m >> ar >> ac;
        --ar; --ac;
        vector<char> op(4);
        vector<int> k(4), c(p);
        rep(i, 4) cin >> op[i] >> k[i];
        vector ids(n, vector(n, -1));
        rep(i, p) {
            int xi, yi;
            cin >> xi >> yi >> c[i];
            --xi; --yi;
            ids[xi][yi] = i;
        }
        vector dp(n, vector(n, vector(1<<p, vector(m+1, -LINF))));
        rep(i, n) rep(j, n) if (i==ar && j==ac) dp[i][j][0][0] = 0;
        rep3(t, 1, m+1) rep(s, 1<<p) rep(i, n) rep(j, n) {
            chmax(dp[i][j][s][t], dp[i][j][s][t-1]);
            rep(i2, 4) {
                int ni = i + di[i2], nj = j + dj[i2];
                if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
                if (dp[ni][nj][s][t-1] != -LINF) chmax(dp[i][j][s][t], calc(dp[ni][nj][s][t-1], op[i2], k[i2]));
                if (ids[i][j]==-1 || !(s&(1<<ids[i][j]))) continue;
                if (dp[ni][nj][s^(1<<ids[i][j])][t-1] != -LINF) chmax(dp[i][j][s][t], calc(dp[ni][nj][s^(1<<ids[i][j])][t-1],op[i2],k[i2])+c[ids[i][j]]);
            }
        }
        ll res = -LINF;
        rep(i, n) rep(j, n) chmax(res, dp[i][j][(1<<p)-1][m]);
        cout << "Case #" << i0 << ": ";
        if (res == -LINF) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
    }
    return 0;
}
