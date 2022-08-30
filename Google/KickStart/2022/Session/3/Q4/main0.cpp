// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int VMAX = 5000;

int main() {
    int t0;
    cin >> t0;
    vector<int> bcnt;
    rep3(i0, 1, t0+1) {
        int n, p;
        cin >> n;
        bcnt.assign(VMAX+2, 0);
        rep(i, n) {
            int ai, bi;
            cin >> ai >> bi;
            bcnt[ai]++;
            bcnt[bi+1]--;
        }
        rep(i, VMAX+1) bcnt[i+1] += bcnt[i];
        cin >> p;
        cout << "Case #" << i0 << ": ";
        rep(i, p) {
            int ci;
            cin >> ci;
            cout << bcnt[ci] << (i<p-1?' ':'\n');
        }
    }
    return 0;
}
