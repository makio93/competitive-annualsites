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
        int n;
        string c1;
        cin >> n >> c1;
        vector<string> c;
        c.push_back(c1);
        rep(i, 1<<10) {
            string ci;
            rep(j, 10) {
                if ((i>>j)&1) ci.push_back('-');
                else ci.push_back('.');
            }
            int clen = min(c[0].length(), ci.length());
            if (c[0].substr(0, clen) == ci.substr(0, clen)) continue;
            c.push_back(ci);
            if ((int)(c.size()) >= n) break;
        }
        cout << "Case #" << i0 << ":" << endl;
        rep3(i, 1, n) cout << c[i] << endl;
    }
    return 0;
}
