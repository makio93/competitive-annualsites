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
        int sum = 0;
        rep(i, n) sum += s[i] - '0';
        int rval = (9 - sum%9) % 9;
        string res = string("") + (char)(rval+'0') + s;
        int m = res.length(), id = 0;
        if (rval == 0) {
            swap(res[0], res[1]);
            ++id;
        }
        while (id < m-1) {
            if (res[id] < res[id+1]) break;
            swap(res[id], res[id+1]);
            ++id;
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
