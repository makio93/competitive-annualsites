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
        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        rep(i, n) cin >> s[i];
        int mval = *max_element(all(s));
        vector<int> scnt(mval+1);
        rep(i, n) scnt[s[i]]++;
        bool res = true;
        if (*max_element(all(scnt)) >= 3) res = false;
        int cnt2 = 0, cnt1 = 0;
        rep(i, mval+1) {
            if (scnt[i] == 2) cnt2++;
            else if (scnt[i] == 1) cnt1++;
        }
        if (cnt2+(cnt1+1)/2 > k) res = false;
        cout << "Case #" << i0 << ": " << (res ? "YES" : "NO") << endl;
    }
    return 0;
}
