// 本番4,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, k;
        cin >> n >> k;
        unordered_set<int> visited;
        set<int> unused;
        rep(i, n) unused.insert(i);
        double sum = 0.0;
        int pri = -1, roop = max(1, (int)sqrt(k)), bi = k / roop, bcnt = 0;
        int scnt = 0;
        ll ssum = 0;
        rep(i, k+1) {
            int ri, pi;
            cin >> ri >> pi;
            --ri;
            bool nbi = false;
            if (visited.find(ri) == visited.end()) {
                visited.insert(ri);
                unused.erase(ri);
                ssum += pi;
                ++scnt;
            }
            if (i==k || (i!=0&&i%roop==0&&bcnt<bi)) {
                sum += (double)ssum / scnt;
                ssum = 0, scnt = 0;
                ++bcnt;
                nbi = true;
            }
            if (i == k) {
                ll res = min((ll)n*(n-1)/2, max({ 1LL, (ll)(n+1)/2, (ll)round(sum/bcnt/2.0*n) }));
                cout << "E " << res << endl;
                break;
            }
            else {
                if (nbi) cout << "T " << ((*unused.begin())+1) << endl;
                else cout << 'W' << endl;
            }
        }
    }
    return 0;
}
