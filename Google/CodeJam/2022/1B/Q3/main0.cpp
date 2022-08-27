// 本番WA

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
    rep(i0, t0) {
        const string tar = "00000001";
        bool fin = false;
        while (1) {
            cout << tar << endl;
            int val;
            cin >> val;
            if (val == 0) break;
            if (val == -1) {
                fin = true;
                break;
            }
            if (val == 8) {
                string tar2 = "11111111";
                cout << tar2 << endl;
                cin >> val;
                if (val == 0) break;
                if (val == -1) {
                    fin = true;
                    break;
                }
            }
        }
        if (fin) break;
    }
    return 0;
}
