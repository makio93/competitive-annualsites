#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        vector<vector<int>> g(n);
        rep(i, n-1) {
            int ai, bi;
            cin >> ai >> bi;
            --ai; --bi;
            g[ai].push_back(bi);
            g[bi].push_back(ai);
        }
        int res = c[0];
        if (k > 0) {
            vector<int> vals;
            function<int(int,int)> dfs = [&](int v, int p) -> int {
                int mval = -1;
                for (int t : g[v]) if (t != p) {
                    int rval = dfs(t, v);
                    if (mval == -1) mval = rval;
                    else {
                        vals.push_back(min(mval, rval));
                        mval = max(mval, rval);
                    }
                }
                if (mval == -1) mval = 0;
                return mval + c[v];
            };
            vector<int> vals0;
            for (int ti : g[0]) vals0.push_back(dfs(ti, 0));
            sort(vals0.rbegin(), vals0.rend());
            sort(vals.rbegin(), vals.rend());
            vector<int> dvals1, dvals2;
            dvals1.push_back(0);
            int l1 = vals0.size(), l2 = vals.size();
            for (int i=0; i<l1; i+=2) {
                if (i+1 < l1) dvals1.push_back(vals0[i]+vals0[i+1]);
                else dvals1.push_back(vals0[i]);
            }
            dvals2.push_back(0);
            if (!vals.empty()) dvals2.push_back(vals[0]);
            for (int i=1; i<l2; i+=2) {
                if (i+1 < l2) dvals2.push_back(vals[i]+vals[i+1]);
                else dvals2.push_back(vals[i]);
            }
            vector<int> sum1(dvals1.size()), sum2(dvals2.size());
            int s1 = sum1.size(), s2 = sum2.size();
            rep3(i, 1, s1) sum1[i] = sum1[i-1] + dvals1[i];
            rep3(i, 1, s2) sum2[i] = sum2[i-1] + dvals2[i];
            int mval0 = 0;
            rep(i, k+1) mval0 = max(mval0, sum1[min(s1-1,i)]+sum2[min(s2-1,k-i)]);
            res += mval0;
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
