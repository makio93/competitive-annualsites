// 本番AC

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
        int r, c;
        cin >> r >> c;
        vector<string> b(r);
        rep(i, r) cin >> b[i];
        cout << "Case #" << i0 << ": ";
        if (r==1 || c==1) {
            bool tr = false;
            rep(i, r) if (count(all(b[i]), '^') > 0) tr = true;
            if (tr) cout << "Impossible" << endl;
            else {
                cout << "Possible" << endl;
                rep(i, r) cout << b[i] << endl;
            }
        }
        else {
            cout << "Possible" << endl;
            rep(i, r) cout << string(c, '^') << endl;
        }
    }
    return 0;
}
