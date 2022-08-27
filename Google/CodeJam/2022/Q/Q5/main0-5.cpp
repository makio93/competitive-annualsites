// 本番5,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, k;
        cin >> n >> k;
        unordered_set<int> unused;
        rep(i, n) unused.insert(i);
        ll sum = 0;
        rep(i, k+1) {
            int ri, pi;
            cin >> ri >> pi;
            --ri;
            unused.erase(ri);
            sum += pi;
            if (unused.empty()) break;
            if (i == k) break;
            cout << "T " << ((*unused.begin())+1) << endl;
        }
        ll res = 0;
        if (unused.empty()) res = sum / 2;
        else {
            //ll lval = max(1LL, (sum+sub)/2), rval = min((ll)n*(n-1)/2, (sum+(ll)sub*(sub-1))/2);
            //res = lval + (rval-lval) / 2;
            res = (ll)(sum / (double)k * n) / 2;
            res = min((ll)n*(n-1)/2, max((ll)(n+1)/2, res));
        }
        cout << "E " << res << endl;
    }
    return 0;
}
