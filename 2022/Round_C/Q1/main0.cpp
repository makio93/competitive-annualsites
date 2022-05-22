// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const string sch = "#@*&";

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        string s;
        cin >> n >> s;
        bool ok = false;
        for (char ci : s) if (isupper(ci)) ok = true;
        if (!ok) s.push_back('A');
        ok = false;
        for (char ci : s) if (islower(ci)) ok = true;
        if (!ok) s.push_back('a');
        ok = false;
        for (char ci : s) if (isdigit(ci)) ok = true;
        if (!ok) s.push_back('1');
        ok = false;
        for (char ci : s) if (count(all(sch), ci) > 0) ok = true;
        if (!ok) s.push_back('#');
        int m = s.length();
        for (int i=m; i<7; ++i) s.push_back('a');
        cout << "Case #" << i0 << ": " << s << endl;
    }
    return 0;
}
