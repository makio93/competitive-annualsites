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
        ll x, y;
        cin >> n >> x >> y;
        ll s = (ll)n * (n+1) / 2;
        if (s*x%(x+y) != 0) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        ll tar = s * x / (x+y);
        vector<int> lst;
        priority_queue<int> pq;
        rep3(i, 1, n+1) pq.push(i);
        while (!pq.empty()) {
            int val = pq.top(); pq.pop();
            if (tar >= val) {
                lst.push_back(val);
                tar -= val;
            }
        }
        if (tar > 0) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        sort(all(lst));
        cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
        int m = lst.size();
        cout << m << endl;
        rep(i, m) printf("%d%c", lst[i], (i<m-1?' ':'\n'));
    }
    return 0;
}
