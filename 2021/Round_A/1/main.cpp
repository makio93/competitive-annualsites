#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番提出コード（のちに少し手直し）/AC

int main(){
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        rep(i, n/2) if (s[i] != s[n-i-1]) ++cnt;
        cout << "Case #" << i1 << ": " << abs(k-cnt) << endl;
    }
    return 0;
}
