#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
const string tar = "XO.F";

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        string w;
        cin >> n >> w;
        ll li = -1, ri = -1, pri = -1, add = 0, pos = -1;
        int lhand = -1, hand = -1;
        rep(i, n) {
            ++pos;
            rep(j, 4) if (w[i] == tar[j]) {
                if (j < 2) {
                    if (hand == -1) {
                        lhand = hand = j;
                        pri = li = pos;
                    }
                    else if (hand != j) {
                        hand = j;
                        ri = pri;
                        pri = li = pos;
                        add = (add + ri+1) % mod;
                    }
                    else pri = pos;
                }
                else if (j == 2) {
                    
                }
            }
        }
    }
    return 0;
}
