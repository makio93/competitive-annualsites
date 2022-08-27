#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const string tar = "XO";

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        string w;
        cin >> n >> w;
        int hand = -1, fval = 0;
        rep(i, n) rep(j, 2) if (w[i] == tar[j]) {
            if (hand == -1) hand = j;
            else {
                if (hand != j) {
                    hand = j;
                    ++fval;
                }
            }
        }
        cout << "Case #" << i0 << ": " << fval << endl;
    }
    return 0;
}
