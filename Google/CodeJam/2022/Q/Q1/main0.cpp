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
        int ri = r*2 + 1, ci = c*2 + 1;
        cout << "Case #" << i0 << ":" << endl;
        rep(i, ri) {
            rep(j, ci) {
                if (i%2 == 0) {
                    if ((i+j)%2 == 0) {
                        if (i+j == 0) cout << '.';
                        else cout << '+';
                    }
                    else {
                        if (i+j <= 1) cout << '.';
                        else cout << '-';
                    }
                }
                else {
                    if ((i+j)%2 == 0) cout << '.';
                    else {
                        if (i+j <= 1) cout << '.';
                        else cout << '|';
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}
