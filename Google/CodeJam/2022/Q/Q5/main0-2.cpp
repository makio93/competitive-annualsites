// 本番2,WA

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
        unordered_set<int> unvisited;
        rep(i, n) unvisited.insert(i);
        double sum = 0.0;
        bool isw = false;
        rep(i, k+1) {
            int ri, pi;
            cin >> ri >> pi;
            --ri;
            if (unvisited.find(ri) != unvisited.end()) {
                unvisited.erase(ri);
                if (!isw) sum += pi;
                else sum += (pi-1);
            }
            isw = false;
            if (i<k && (int)(unvisited.size())>=n/2) {
                if (!unvisited.empty()) {
                    cout << "T " << ((*unvisited.begin())+1) << endl;
                }
                else {
                    cout << 'W' << endl;
                    isw = true;
                }
            }
            else if (i < k) {
                cout << 'W' << endl;
                isw = true;
            }
            else {
                int klen = n - (int)(unvisited.size());
                ll res = min((ll)n*(n-1)/2, max({ 1LL, (ll)n/2, (ll)round(sum/klen/2.0*n) }));
                cout << "E " << res << endl;
            }
        }
    }
    return 0;
}
