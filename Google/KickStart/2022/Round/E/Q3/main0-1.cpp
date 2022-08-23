// 本番,WA(誤読)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct SegmentTree {
    int n;
    vector<int> dat;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, (int)(1e9));
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return (int)(1e9);
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m;
        string p, q;
        cin >> n >> p;
        q = p;
        p.push_back('$');
        reverse(all(q));
        p += q;
        m = p.length();
        vector<int> sa(m+1), rank(m+1), lcp(m+1);
        rep(i, m+1) {
            sa[i] = i;
            rank[i] = (i < m) ? (int)(p[i]) : -1;
        }
        for (int k=1; k<=m; k*=2) {
            auto comp_sa = [&](int li, int ri) -> bool { return make_pair(rank[li], (li+k<=m)?rank[li+k]:-1) < make_pair(rank[ri], (ri+k<=m)?rank[ri+k]:-1); };
            sort(all(sa), comp_sa);
            vector<int> rtmp(m+1);
            rtmp[sa[0]] = 0;
            rep3(i, 1, m+1) rtmp[sa[i]] = rtmp[sa[i-1]] + (comp_sa(sa[i-1], sa[i]) ? 1 : 0);
            rep(i, m+1) rank[i] = rtmp[i];
        }
        int h = 0;
        lcp[0] = 0;
        rep(i, m) {
            int id = sa[rank[i]-1];
            if (h > 0) --h;
            while (id+h<m && i+h<m) {
                if (p[id+h] != p[i+h]) break;
                ++h;
            }
            lcp[rank[i]-1] = h;
        }
        SegmentTree rmq(m+1);
        rep(i, m+1) rmq.update(i, lcp[i]);
        int mval = n;
        rep3(i, 1, n) {
            int len = n - i, rlen = (len+1) / 2, li = n - (len+1)/2, ri = n + 1 + len/2;
            if (rmq.query(min(rank[li], rank[ri]), max(rank[li], rank[ri])) == (len+1)/2) mval = min(mval, i);
        }
        string res = p.substr(0, mval);
        reverse(all(res));
        cout << res << endl;
    }
    return 0;
}
