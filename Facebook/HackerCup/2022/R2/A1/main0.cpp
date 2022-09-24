// 本番AC

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
    rep3(i0, 1, t0+1) {
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> ccnt(n+1, vector<int>(26));
        rep(i, n) {
            int cid = s[i] - 'a';
            ccnt[i+1][cid]++;
            rep(j, 26) ccnt[i+1][j] += ccnt[i][j];
        }
        int q, res = 0;
        cin >> q;
        rep(i, q) {
            int li, ri;
            cin >> li >> ri;
            --li;
            if ((ri-li)%2 == 0) continue;
            vector<int> lcnt(26), rcnt(26);
            int len = (ri-li) / 2, ci = li + len;
            rep(j, 26) lcnt[j] += ccnt[ci][j] - ccnt[li][j];
            rep(j, 26) rcnt[j] += ccnt[ri][j] - ccnt[ci][j];
            int tcnt = 0;
            rep(j, 26) {
                if (rcnt[j]-lcnt[j] == 0) continue;
                if (rcnt[j]-lcnt[j] == 1) ++tcnt;
                else {
                    tcnt = -1;
                    break;
                }
            }
            if (tcnt == 1) {
                ++res;
                continue;
            }
            lcnt.assign(26, 0); rcnt.assign(26, 0);
            ++ci;
            rep(j, 26) lcnt[j] += ccnt[ci][j] - ccnt[li][j];
            rep(j, 26) rcnt[j] += ccnt[ri][j] - ccnt[ci][j];
            tcnt = 0;
            rep(j, 26) {
                if (lcnt[j]-rcnt[j] == 0) continue;
                if (lcnt[j]-rcnt[j] == 1) ++tcnt;
                else {
                    tcnt = -1;
                    break;
                }
            }
            if (tcnt == 1) ++res;
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
