#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
const string tar = "XO";

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        string w;
        cin >> n >> w;
        vector<int> lb, rb;
        int hand = -1;
        rep(i, n) rep(j, 2) if (w[i] == tar[j]) {
            if (hand == -1) {
                hand = j;
                lb.push_back(i);
            }
            else if (hand != j) {
                hand = j;
                lb.push_back(i);
            }
        }
        hand = -1;
        repr(i, n) rep(j, 2) if (w[i] == tar[j]) {
            if (hand == -1) {
                hand = j;
                rb.push_back(i);
            }
            else if (hand != j) {
                hand = j;
                rb.push_back(i);
            }
        }
        ll res = 0;
        if (!lb.empty()) {
            sort(all(lb));
            sort(all(rb));
            int m = lb.size();
            ll add = 0;
            rep3(i, 1, m) {
                add = (add + rb[i-1]+1) % mod;
                if (i+1 < m) res = (res + add * (lb[i+1] - lb[i])) % mod;
                else res = (res + add * (n - lb[i])) % mod;
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
