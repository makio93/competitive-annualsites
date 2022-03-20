// 本番提出2,Set1のみAC

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
    const string roop = "110100";
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n <= 4) {
            cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
            continue;
        }
        else if (n <= 15) {
            bool res = false;
            rep(i1, (1<<n)) {
                string tar = "";
                int tval = i1;
                rep(i, n) {
                    tar.push_back((char)(tval%2+'0'));
                    tval /= 2;
                }
                bool ok = true;
                rep(li, n) {
                    rep3(ri, li+5, n+1) {
                        string tmp = tar.substr(li, ri-li), rtmp = tmp;
                        reverse(all(rtmp));
                        if (tmp == rtmp) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (!ok) continue;
                rep(i, n) {
                    if (s[i] == '?') continue;
                    else {
                        if (s[i] != tar[i]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    res = true;
                    break;
                }
            }
            if (res) cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
            else cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        }
        else {
            int rcnt = (n+5) / 6;
            string cent = "";
            rep(i, rcnt) cent += roop;
            vector<string> tmps, tars;
            rep(i, 5) rep(j, 5) rep(i1, 2) rep(j1, 2) {
                string tstr = string(i, (char)(i1+'0')) + cent + string(j, (char)(j1+'0'));
                string rstr = tstr;
                reverse(all(rstr));
                bool ok2 = true;
                int len = 1, tlen = tstr.length();
                rep3(i2, 1, tlen) {
                    if (tstr[i2-1] == tstr[i2]) ++len;
                    else break;
                }
                if (len > 4) ok2 = false;
                len = 1;
                rep3(i2, 1, tlen) {
                    if (rstr[i2-1] == rstr[i2]) ++len;
                    else break;
                }
                if (len > 4) ok2 = false;
                if (!ok2) continue;
                tmps.push_back(tstr);
            }
            for (string tar : tmps) {
                tars.push_back(tar);
                reverse(all(tar));
                tars.push_back(tar);
            }
            int tlen = tars.size(), m = tars.front().size();
            bool res = false;
            rep(i1, tlen) {
                rep(i, m-n+1) {
                    bool ok = true;
                    rep(j, n) {
                        if (s[j] == '?') continue;
                        else {
                            if (s[j] != tars[i1][i+j]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        res = true;
                        break;
                    }
                }
                if (res) break;
            }
            if (res) cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
            else cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
