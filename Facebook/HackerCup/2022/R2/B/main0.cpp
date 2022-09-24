// 本番TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n), x(n), y(n);
        rep(i, n) cin >> a[i] >> b[i] >> x[i] >> y[i];
        map<int, vector<int>> alst;
        rep(i, n) alst[a[i]].push_back(i);
        vector<multiset<ll>> vpq(n);
        multiset<ll> vlst;
        for (auto itr=alst.begin(); itr!=alst.end(); ++itr) {
            for (int& id : itr->second) {
                vpq[id].insert(0);
                if ((int)(vpq[id].size()) > k) vpq[id].erase(vpq[id].begin());
                if (alst.find(b[id]) == alst.end()) continue;
                for (int& tid : alst[b[id]]) if (x[tid] > y[id]) {
                    ll sval = x[tid] - y[id];
                    for (auto ritr=vpq[id].rbegin(); ritr!=vpq[id].rend(); ++ritr) {
                        ll nval = *ritr + sval;
                        if ((int)(vpq[tid].size())>=k && *vpq[tid].begin()>=nval) break;
                        if ((int)(vlst.size())>=k && *vlst.begin()>=nval) break;
                        vpq[tid].insert(nval);
                        if ((int)(vpq[tid].size()) > k) vpq[tid].erase(vpq[tid].begin());
                        vlst.insert(nval);
                        if ((int)(vlst.size()) > k) vlst.erase(vlst.begin());
                    }
                }
            }
        }
        ll res = 0;
        if (!vlst.empty()) for (auto itr=vlst.rbegin(); itr!=vlst.rend(); ++itr) res = (res + *itr) % mod;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
