#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中に実装、WA

int main() {
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> u(n);
        rep(i, n) cin >> u[i];
        map<int, int> ucnt;
        rep(i, n) if (u[i] > 0) ucnt[i+1] = u[i];
        int rcnt = 0;
        bool imp = false;
        while (!((int)(ucnt.size())==1)) {
            ++rcnt;
            int val1 = ucnt.begin()->first, val2 = val1 + (b-a), valt = val1 + b;
            int tcnt = ucnt[val1];
            ucnt[valt] += tcnt;
            ucnt[val1] -= tcnt;
            if (ucnt[val1] <= 0) ucnt.erase(val1);
            ucnt[val2] -= tcnt;
            if (ucnt[val2] <= 0) ucnt.erase(val2);
            if (rcnt > (int)(1e3)) {
                imp = true;
                break;
            }
        }
        int res = ucnt.begin()->first;
        if (!imp && ucnt.begin()->second>1) {
            res += ucnt.begin()->second/2;
            if (ucnt.begin()->second%2==0) ++res;
        }
        cout << "Case #" << i1 << ": ";
        if (!imp) cout << res << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
