#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番TE

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        rep(i, n) {
            int ci;
            cin >> ci;
            c[i] = -ci;
        }
        vector<unordered_map<int, int>> g(n);
        rep(i, n-1) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[ai][bi] = i;
            g[bi][ai] = i;
        }
        priority_queue<pair<int, tuple<int, int, ll, ll>>, vector<pair<int, tuple<int, int, ll, ll>>>, greater<pair<int, tuple<int, int, ll, ll>>>> pq;
        vector<vector<map<pair<ll, ll>, int>>> dist(n, vector<map<pair<ll, ll>, int>>(k+1));
        pq.emplace(c[0], make_tuple(0, 0, 1LL, 0LL));
        dist[0][0][{1LL,0LL}] = c[0];
        while (!pq.empty()) {
            auto [ ci, ti ] = pq.top(); pq.pop();
            auto [ ki, vi, pi, ei ] = ti;
            if (dist[vi][ki].find({pi,ei})==dist[vi][ki].end() || (dist[vi][ki].find({pi,ei})!=dist[vi][ki].end()&&dist[vi][ki][{pi,ei}]!=ci)) continue;
            rep(i, n) if (i != vi) {
                int ci2 = ci, ki2 = ki, vi2 = i;
                ll pi2 = (pi | (1LL<<vi2)), ei2 = ei;
                if (((pi>>vi2)&1) == 0) ci2 += c[vi2];
                if (g[vi].find(vi2) != g[vi].end()) {
                    int eval = g[vi][vi2];
                    if (((ei>>eval)&1) == 0) {
                        ll ei1 = (ei | (1LL<<eval));
                        if (ki2<=k && (dist[vi2][ki2].find({pi2,ei1})==dist[vi2][ki2].end()||dist[vi2][ki2][{pi2,ei1}]>ci2)) {
                            if (dist[vi2][ki2].find({pi2,ei1}) == dist[vi2][ki2].end()) dist[vi2][ki2][{pi2,ei1}] = ci2;
                            else dist[vi2][ki2][{pi2,ei1}] = min(dist[vi2][ki2][{pi2,ei1}], ci2);
                            pq.emplace(ci2, make_tuple(ki2, vi2, pi2, ei1));
                        }
                    }
                }
                ki2++;
                if (ki2 > k) continue;
                if (dist[vi2][ki2].find({pi2,ei2})!=dist[vi2][ki2].end() && dist[vi2][ki2][{pi2,ei2}]<=ci2) continue;
                if (dist[vi2][ki2].find({pi2,ei2}) == dist[vi2][ki2].end()) dist[vi2][ki2][{pi2,ei2}] = ci2;
                else dist[vi2][ki2][{pi2,ei2}] = min(dist[vi2][ki2][{pi2,ei2}], ci2);
                pq.emplace(ci2, make_tuple(ki2, vi2, pi2, ei2));
            }
        }
        int mval = 0;
        rep(i, k+1) for (auto p : dist[0][i]) mval = max(mval, -p.second);
        cout << "Case #" << i0 << ": " << mval << endl;
    }
    return 0;
}
