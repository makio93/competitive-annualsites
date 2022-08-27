#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        string y;
        cin >> y;
        vector<string> sl;
        int len = y.length();
        rep3(i, 1, (len/2+1)) {
            ll tval = stoll(y.substr(0, i));
            string tres;
            for (int j=0; j<len; j+=(int)(to_string(tval).length())) {
                tres += to_string(tval);
                ++tval;
            }
            sl.push_back(tres);
            tval = stoll(y.substr(0, i));
            bool single = false;
            if ((to_string(tval+1).length()) > i) single = true;
            if (single) continue;
            ++tval;
            tres = "";
            for (int j=0; j<len; j+=(int)(to_string(tval).length())) {
                tres += to_string(tval);
                ++tval;
            }
            sl.push_back(tres);
        }
        int tl = len / 2 + 1;
        ll tval = 1;
        rep(i, tl-1) tval *= 10;
        string tres;
        for (int j=0; j<len+1; j+=(int)(to_string(tval).length())) {
            tres += to_string(tval);
            ++tval;
        }
        sl.push_back(tres);
        vector<string> sl1, sl2, sl3;
        for (string si : sl) {
            if (si.length() == y.length()) sl1.push_back(si);
            else if (si.length() == y.length()+1) sl2.push_back(si);
            else if (si.length() == y.length()+2) sl3.push_back(si);
        }
        sort(all(sl1)); sort(all(sl2)); sort(all(sl3));
        string ans = "";
        for (string si : sl1) {
            if (si > y) {
                ans = si;
                break;
            }
        }
        if (ans.empty()) {
            if (!sl2.empty()) ans = sl2.front();
            else ans = sl3.front();
        }
        cout << "Case #" << i1 << ": " << ans << endl;
    }
    return 0;
}
