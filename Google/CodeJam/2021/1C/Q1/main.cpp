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
        int n, k;
        cin >> n >> k;
        vector<int> p;
        rep(i, n) {
            int pi;
            cin >> pi;
            p.push_back(pi);
        }
        sort(all(p));
        p.erase(unique(all(p)), p.end());
        int n2 = p.size();
        vector<int> sub, sub2;
        sub.push_back(p.front()-1);
        rep3(i, 1, n2) {
            sub.push_back(((p[i]-p[i-1]-1)+1)/2);
            sub2.push_back((p[i]-p[i-1]-1));
        }
        sub.push_back(k-p.back());
        sort(sub.rbegin(), sub.rend());
        sort(sub2.rbegin(), sub2.rend());
        int mval = sub[0] + sub[1];
        if (!sub2.empty()) mval = max(mval, sub2.front());
        double ans = (double)(mval) / k;
        cout << "Case #" << i1 << ": ";
        printf("%.10f\n", ans);
    }
    return 0;
}
