#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説を見てから実装、よくわからない

int main() {
    int t;
    cin >> t;
    const ll lap = 360LL * 12LL * (ll)(1e10);
    rep3(i1, 1, t+1) {
        vector<ll> h(3);
        rep(i, 3) cin >> h[i];
        vector<vector<ll>> candi;
        rep(i, 3) rep(j, 3) {
            if (i == j) continue;
            ll ang = h[j] - h[i];
            if (ang < 0LL) ang = (h[j]+lap) - h[i];
            rep(i2, 12) if ((i2*3600LL*(ll)(1e9)+ang)>=0LL && (i2*3600LL*(ll)(1e9)+ang)%11LL==0LL) {
                ll nsec = (i2*3600LL*(ll)(1e9)+ang) / 11LL;
                candi.push_back(vector<ll>({i2,nsec}));
            }
        }
        if (candi.empty()) {
            cout << "Case #" << i1 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        else {
            bool ok = false;
            rep(i, 3) h[i] -= h[0];
            for (auto tvec : candi) {
                ll tnsec = tvec[0] * 3600LL * (ll)(1e9) + tvec[1];
                ll hang = tnsec, mang = tnsec * 12LL % lap, sang = tnsec * 720LL % lap, ni = tnsec % (ll)(1e9);
                vector<ll> h2 = { hang, mang, sang };
                sort(all(h2));
                rep(i, 3) h2[i] -= h2[0];
                bool same = false;
                cout << h2[0] << ' ' << h2[1] << ' ' << h2[2] << endl;
                rep(i2, 3) {
                    auto h3 = h2;
                    rep(j, 3) h3[j] -= h2[i2];
                    rep(j, 3) if (h3[j] < 0LL) h3[j] += lap;
                    sort(all(h3));
                    bool same2 = true;
                    rep(j, 3) if (h3[j] != h[j]) same2 = false;
                    if (same2) {
                        same = true;
                        h2 = h3;
                        break;
                    }
                }
                if (same) {
                    ll hi = tvec[0], mi = mang / (6LL*12LL*(ll)(1e10)), si = sang / (6LL*12LL*(ll)(1e10));
                    cout << "Case #" << i1 << ": " << hi << ' ' << mi << ' ' << si << ' ' << ni << endl;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "Case #" << i1 << ": " << "IMPOSSIBLE" << endl;
                cout << "checked" << endl;
            }
        }
    }
    return 0;
}
