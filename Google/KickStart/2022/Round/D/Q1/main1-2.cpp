// 解説AC,O(n)解

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
        nth_element(a.begin(), a.begin()+m-1, a.end(), greater<int>());
        ll res = accumulate(a.begin(), a.begin()+m-1, 0LL) * 2;
        int r = n - m + 1;
        if (r%2 == 1) {
            nth_element(a.begin()+m-1, a.begin()+m-1+r/2, a.end(), greater<int>());
            res += a[m-1+r/2] * 2;
        }
        else {
            nth_element(a.begin()+m-1, a.begin()+m-1+r/2-1, a.end(), greater<int>());
            nth_element(a.begin()+m-1+r/2, a.begin()+m-1+r/2, a.end(), greater<int>());
            res += a[m-1+r/2-1] + a[m-1+r/2];
        }
        cout << "Case #" << i0 << ": ";
        cout << fixed << setprecision(1) << (res/2.0) << endl;
    }
    return 0;
}
