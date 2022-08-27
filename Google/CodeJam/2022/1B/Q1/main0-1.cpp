// 本番作成,未提出,WA

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
        int n;
        cin >> n;
        deque<int> d(n);
        rep(i, n) cin >> d[i];
        int cnt = 0, pval = 0;
        while (!d.empty()) {
            if (max(d.front(), d.back()) >= pval) {
                if (min(d.front(), d.back()) >= pval) {
                    if (d.front() <= d.back()) {
                        pval = d.front();
                        d.pop_front();
                    }
                    else {
                        pval = d.back();
                        d.pop_back();
                    }
                }
                else {
                    if (d.front() >= d.back()) {
                        pval = d.front();
                        d.pop_front();
                    }
                    else {
                        pval = d.back();
                        d.pop_back();
                    }
                }
                ++cnt;
            }
            else {
                if (d.front() <= d.back()) {
                    pval = d.front();
                    d.pop_front();
                }
                else {
                    pval = d.back();
                    d.pop_back();
                }
            }
        }
        cout << "Case #" << i0 << ": " << cnt << endl;
    } 
    return 0;
}
