#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const string cols = "UBYGRPOA";

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        string p;
        cin >> n >> p;
        vector<int> vals(n);
        rep(i, n) vals[i] = cols.find(p[i]);
        vector<vector<int>> sub(3, vector<int>(n+1));
        rep(i, 3) rep(j, n) sub[i][j+1] = ((vals[j]>>i) & 1) - ((j-1>=0) ? ((vals[j-1]>>i)&1) : 0);
        int res = 0;
        rep(i, 3) rep(j, n+1) if (sub[i][j] == 1) ++res;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
