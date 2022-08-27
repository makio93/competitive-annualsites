#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        vector<vector<int>> g(n);
        rep(i, n-1) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[ai].push_back(bi);
            g[bi].push_back(ai);
        }
        vector<vector<vector<int>>> fval(n, vector<vector<int>>(k+1, vector<int>(2)));
        map<tuple<int, int, int, int, int>, int> gval;
        vector<int> parents(n, -1);
        function<int(int,int,int)> calc = [&](int v, int ji, int ki) -> int {
            vector<int> children;
            for (int t : g[v]) if (t != parents[v]) {
                children.push_back(t);
                parents[t] = v;
            }
            int clen = children.size();
            int ri = (ki == 1) ? 0 : c[v];
            if (ki == 1) gval[{v, ji, ki, 0, 0}] = c[v];
            rep3(i1, 1, clen+1) {
                if (ki == 1) {
                    rep(j1, ji+1) {
                        int fren = calc(children[i1-1], ji-j1, ki);
                        gval[{v,ji,ki,i1,1}] = max(gval[{v,ji-j1,ki,i1-1,0}]+calc(children[i1-1],j1,1), )
                    }
                }
            }
        };
    }
    return 0;
}
