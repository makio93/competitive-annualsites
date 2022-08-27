// 本番,Set1のみAC

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
        bool fin = false;
        int bt = 4;
        do {
            string tar = string(bt, '1') + string(8-bt, '0');
            cout << tar << endl;
            cin >> bt;
            if (bt == 0) break;
            if (bt == -1) {
                fin = true;
                break;
            }
            bt = max(bt, 8-bt);
        } while (1);
        if (fin) break;
    }
    return 0;
}
