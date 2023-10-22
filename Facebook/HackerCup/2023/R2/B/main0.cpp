// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

struct MinSeg {
    int n;
    vector<int> dat;
    MinSeg() { init(1); }
    MinSeg(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, (int)(2e9));
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
        if (r<=a || b<=l) return (int)(2e9);
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};

struct MaxSeg {
    int n;
    vector<int> dat;
    MaxSeg() { init(1); }
    MaxSeg(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, (int)(-1e9));
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = max(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return (int)(-1e9);
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }
};

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        vector<int> a(n*4), b(n*4);
        rep(i, n) {
            int ai;
            cin >> ai;
            a[i] = a[2*n+i] = ai;
        }
        rep(i, n) {
            int bi;
            cin >> bi;
            a[n+i] = a[3*n+i] = bi;
        }
        rep(i, 4*n) b[i] = a[i] - a[(i+n)%(4*n)];
        MinSeg lsg(4*n);
        MaxSeg rsg(4*n);
        rep(i, 4*n) {
            lsg.update(i, b[i]);
            rsg.update(i, b[i]);
        }
        vector<int> ids;
        rep(i, 2*n) {
            int lv1 = rsg.query(i, i+n/2), rv1 = lsg.query(i+n-n/2, i+n);
            int rv2 = lsg.query(i+n, i+n+n/2), lv2 = rsg.query(i+2*n-n/2, i+2*n);
            if (lv1 < 0 && rv1 > 0 && rv2 > 0 && lv2 < 0) ids.push_back(i);
        }
        int res = -1;
        for (const int& id : ids) {
            bool ok = true;
            rep(i, n) if (a[id+i] != a[id+2*n-1-i]) ok = false;
            if (ok) {
                res = id;
                break;
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
