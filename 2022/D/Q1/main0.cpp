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
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        sort(a.rbegin(), a.rend());
        ll res = 0;
        rep(i, m-1) res += a[i] * 2;
        if ((n-(m-1))%2 == 1) res += a[m-2+(n-(m-1)+1)/2] * 2;
        else res += a[m-2+(n-(m-1))/2] + a[m-2+(n-(m-1))/2+1];
        cout << "Case #" << i0 << ": ";
        cout << fixed << setprecision(1) << (res/2.0) << endl;
    }
    return 0;
}
