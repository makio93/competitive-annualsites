#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const int INF = (int)(1e9);

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> trs;
        rep(i, n) if (s[i] == '1') trs.push_back(i+1);
        ll res = 0;
        rep3(i, 1, n+1) {
            int d = distance(trs.begin(), lower_bound(all(trs), i));
            int dval = INF;
            if (d < (int)(trs.size())) dval = abs(trs[d]-i);
            if (d-1 >= 0) dval = min(dval, abs(trs[d-1]-i));
            res += dval;
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
