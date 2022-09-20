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
        int n, q;
        cin >> n >> q;
        vector<vector<int>> g(n);
        rep(i, n-1) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[ai].push_back(bi);
            g[bi].push_back(ai);
        }
        vector<int> qi(q);
        rep(i, q) cin >> qi[i];
        vector<int> dcnt;
        vector<bool> dist(n);
        queue<int> que;
        que.push(0);
        dist[0] = true;
        while (!que.empty()) {
            dcnt.push_back((int)(que.size()));
            int qlen = que.size();
            rep(i, qlen) {
                int vi = que.front(); que.pop();
                for (int& ti : g[vi]) if (!dist[ti]) {
                    que.push(ti);
                    dist[ti] = true;
                }
            }
        }
        int res = 0, dlen = dcnt.size();
        rep(i, dlen) {
            if (res+dcnt[i] <= q) res += dcnt[i];
            else break;
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
