#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        ll y;
        cin >> y;
        int cnt = 0;
        ++y;
        while (cnt < (int)(1e6)) {
            bool ok = false;
            string ystr = to_string(y);
            int ylen = (int)(ystr.length());
            rep3(i, 1, ylen/2+1) {
                bool ok2 = true;
                ll ny = stoll(ystr.substr(0, i));
                int nylen = to_string(ny).length();
                for (int j=i; j<ylen; j+=nylen) {
                    ++ny;
                    nylen = to_string(ny).length();
                    if (ystr.substr(j, nylen) != to_string(ny)) ok2 = false;
                    if (!ok2) break;
                }
                if (ok2) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
            ++y; ++cnt;
        }
        cout << "Case #" << i1 << ": " << y << endl;
    }
    return 0;
}
