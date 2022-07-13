// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const int MVAL = (int)(1e9) + 1;

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m;
        cin >> n;
        vector<int> s(n);
        rep(i, n) {
            cin >> s[i];
            s[i]--;
        }
        cin >> m;
        vector<int> k(m);
        rep(i, m) {
            cin >> k[i];
            k[i]--;
        }
        vector<unordered_map<int, int>> left(m), right(m);
        rep(i, m) {
            for (int j=i; j>=0; --j) if (left[i].find(k[j]) == left[i].end()) left[i][k[j]] = j;
            for (int j=i; j<m; ++j) if (right[i].find(k[j]) == right[i].end()) right[i][k[j]] = j;
        }
        vector<vector<int>> memo(n, vector<int>(m, MVAL));
        auto f = [&](auto f, int x, int y) -> int {
            if (memo[x][y] != MVAL) return memo[x][y];
            if (s[x] != k[y]) return memo[x][y] = INF;
            if (x == 0) return memo[x][y] = 0;
            int ret = INF;
            if (left[y].find(s[x-1]) != left[y].end()) ret = min(ret, f(f, x-1, left[y][s[x-1]]) + abs(y - left[y][s[x-1]]));
            if (right[y].find(s[x-1]) != right[y].end()) ret = min(ret, f(f, x-1, right[y][s[x-1]]) + abs(y - right[y][s[x-1]]));
            return memo[x][y] = ret;
        };
        int res = INF;
        rep(i, m) res = min(res, f(f, n-1, i));
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
