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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int d = n + m - 1, m1 = min(a, b) / d, l1 = (a - m1 * d) + m1, r1 = (b - m1 * d) + m1;
        if (m1 <= 0) cout << "Case #" << i0 << ": " << "Impossible" << endl;
        else {
            vector<vector<int>> grid(n, vector<int>(m, m1));
            grid[0][0] = l1;
            grid[0][m-1] = r1;
            cout << "Case #" << i0 << ": " << "Possible" << endl;
            rep(i, n) rep(j, m) printf("%d%c", grid[i][j], (j<m-1?' ':'\n'));
        }
    }
    return 0;
}
