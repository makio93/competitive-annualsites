// 解説1,MLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);
const ll MVAL = -LINF - 1;
vector<vector<vector<vector<ll>>>> memo;
ll f(vector<int>& a, vector<int>& b, int& n, int& m, int ai, int aj, int bi, int bj, int ki) {
    if (memo[ai+1][aj+1][bi+1][bj+1] != MVAL) return memo[ai+1][aj+1][bi+1][bj+1];
    if (ai+(n-1-aj)>n || bi+(m-1-bj)>m) return memo[ai+1][aj+1][bi+1][bj+1] = -LINF;
    if (ki == 0) return memo[ai+1][aj+1][bi+1][bj+1] = 0;
    ll ret = -LINF;
    if (ai < n) ret = max(ret, f(a, b, n, m, ai+1, aj, bi, bj, ki-1) + a[ai]);
    if (aj >= 0) ret = max(ret, f(a, b, n, m, ai, aj-1, bi, bj, ki-1) + a[aj]);
    if (bi < m) ret = max(ret, f(a, b, n, m, ai, aj, bi+1, bj, ki-1) + b[bi]);
    if (bj >= 0) ret = max(ret, f(a, b, n, m, ai, aj, bi, bj-1, ki-1) + b[bj]);
    return memo[ai+1][aj+1][bi+1][bj+1] = ret;
};

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m, k;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        cin >> m;
        vector<int> b(m);
        rep(i, m) cin >> b[i];
        cin >> k;
        memo.assign(n+2, vector<vector<vector<ll>>>(n+2, vector<vector<ll>>(m+2, vector<ll>(m+2, MVAL))));
        cout << "Case #" << i0 << ": " << f(a, b, n, m, 0, n-1, 0, m-1, k) << endl;
    }
    return 0;
}
