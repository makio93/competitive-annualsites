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
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        int sum = 0;
        rep(i, n) sum += c[i];
        cout << "Case #" << i0 << ": " << (sum % m) << endl;
    }
    return 0;
}
