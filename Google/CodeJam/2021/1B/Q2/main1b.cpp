#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 復習時、解説を見てから実装、Set 2までの解答、AC

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> u(n);
        rep(i, n) cin >> u[i];
        map<int, int> uval;
        rep(i, n) if (u[i] > 0) uval[i+1] = u[i];
        int g = gcd(a, b);
        set<int> gmod;
        for (auto p : uval) gmod.insert(p.first%g);
        if ((int)(gmod.size()) != 1) {
            cout << "Case #" << i1 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        int rval = *gmod.begin();
        while (rval < uval.rbegin()->first) rval += g;
        int mval = uval.rbegin()->first + (1<<9) + *gmod.begin() + 1;
        while (rval <= mval) {
            map<int, int> h, d = uval;
            h[rval] = 1;
            while (!h.empty() && !d.empty()) {
                for (auto itr=d.begin(); itr!=d.end(); ++itr) if (h.find(itr->first) != h.end()) {
                    int sub = min(h[itr->first], itr->second);
                    h[itr->first] -= sub;
                    itr->second -= sub;
                    if (h[itr->first] <= 0) h.erase(itr->first);
                }
                for (auto itr=d.begin(); itr!=d.end(); ) {
                    if (itr->second == 0) itr = d.erase(itr);
                    else ++itr;
                }
                if (!h.empty()) {
                    int mval = h.rbegin()->first, mcnt = h.rbegin()->second;
                    if (mval-a >= 1) h[mval-a] = h[mval-a] + mcnt;
                    if (mval-b >= 1) h[mval-b] = h[mval-b] + mcnt;
                    h.erase(mval);
                }
            }
            if (d.empty()) break;
            rval += g;
        }
        if (rval <= mval) cout << "Case #" << i1 << ": " << rval << endl;
        else cout << "Case #" << i1 << ": " << "IMPOSSIBLE" << endl;
    }
    return 0;
}
