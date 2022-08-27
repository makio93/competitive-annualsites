#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const int INF = (int)(1e9);
const string cset = ".XO";

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        int n;
        cin >> n;
        vector<string> c(n);
        rep(i, n) cin >> c[i];
        vector<vector<int>> rcnt(n, vector<int>(3)), ccnt(n, vector<int>(3));
        int mval = INF;
        map<int, set<set<int>>> scnt;
        rep(i, n) {
            set<int> tmp;
            rep(j, n) {
                rcnt[i][cset.find(c[i][j])]++;
                if (cset.find(c[i][j]) == 0) tmp.insert(i*n+j);
            }
            if (rcnt[i][2] == 0) {
                mval = min(mval, rcnt[i][0]);
                scnt[rcnt[i][0]].insert(tmp);
            }
        }
        rep(i, n) {
            set<int> tmp;
            rep(j, n) {
                ccnt[i][cset.find(c[j][i])]++;
                if (cset.find(c[j][i]) == 0) tmp.insert(j*n+i);
            }
            if (ccnt[i][2] == 0) {
                mval = min(mval, ccnt[i][0]);
                scnt[ccnt[i][0]].insert(tmp);
            }
        }
        string res;
        if (mval == INF) res = "Impossible";
        else res = to_string(mval) + ' ' + to_string((int)(scnt[mval].size()));
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
