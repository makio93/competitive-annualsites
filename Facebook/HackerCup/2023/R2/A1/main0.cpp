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
const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int r, c;
        cin >> r >> c;
        vector<string> a(r);
        rep(i, r) cin >> a[i];
        bool res = false;
        rep(i, r) rep(j, c) if (a[i][j] == 'W') {
            set<pair<int, int>> st;
            queue<pair<int, int>> que;
            que.emplace(i, j);
            a[i][j] = 'M';
            while (!que.empty()) {
                auto [ri, ci] = que.front(); que.pop();
                rep(i2, 4) {
                    int ni = ri + dr[i2], nj = ci + dc[i2];
                    if (ni<0 || ni>=r || nj<0 || nj>=c) continue;
                    if (a[ni][nj] == 'W') {
                        que.emplace(ni, nj);
                        a[ni][nj] = 'M';
                    }
                    else if (a[ni][nj] == '.') st.emplace(ni, nj);
                }
            }
            if ((int)(st.size()) == 1) res = true;
        }
        cout << "Case #" << i0 << ": ";
        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
