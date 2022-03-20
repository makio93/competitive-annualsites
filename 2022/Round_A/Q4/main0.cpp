// 本番提出1,Set1のみAC

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
        ll a, b;
        cin >> a >> b;
        ll res = 0;
        for (ll v=a; v<=b; ++v) {
            string vstr = to_string(v);
            ll sum = 0, mul = 1;
            int m = vstr.length();
            rep(i, m) {
                sum += vstr[i] - '0';
                mul *= vstr[i] - '0';
            }
            if (mul%sum == 0) ++res;
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
