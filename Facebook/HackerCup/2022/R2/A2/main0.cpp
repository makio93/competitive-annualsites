// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int VMAX = (int)(1e6);

struct SegmentTreeXOR {
    int n;
    vector<uint64_t> dat;
    SegmentTreeXOR() { init(1); }
    SegmentTreeXOR(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<uint64_t>(2*n-1);
    }
    void update(int k, uint64_t a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = ((dat[k*2+1]) ^ (dat[k*2+2]));
        }
    }
    uint64_t query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return (uint64_t)(0);
        if (a<=l && r<=b) return dat[k];
        else {
            uint64_t vl = query(a, b, k*2+1, l, (l+r)/2);
            uint64_t vr = query(a, b, k*2+2, (l+r)/2, r);
            return (vl ^ vr);
        }
    }
};

struct BIT {
    int n;
    vector<ll> d;
    BIT(int n=0) : n(n), d(n+1) {}
    void add(int i, ll x=1) {
        for (i++; i<=n; i+=i&-i) {
            d[i] += x;
        }
    }
    ll sum(int i) {
        ll x = 0;
        for (i++; i; i-=i&-i) {
            x += d[i];
        }
        return x;
    }
    ll sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

int main() {
    int t0;
    cin >> t0;
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<uint64_t> hvals(VMAX+1);
    rep(i, VMAX+1) hvals[i] = engine();
    unordered_map<uint64_t, int> htoa;
    rep(i, VMAX+1) htoa[hvals[i]] = i;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        SegmentTreeXOR stx(n+2);
        rep(i, n) stx.update(i, hvals[a[i]]);
        BIT bt(n+2);
        rep(i, n) bt.add(i, a[i]);
        int q, res = 0;
        cin >> q;
        rep(i, q) {
            int qi;
            cin >> qi;
            if (qi == 1) {
                int xi, yi;
                cin >> xi >> yi;
                --xi;
                stx.update(xi, hvals[yi]);
                bt.add(xi, yi-a[xi]);
                a[xi] = yi;
            }
            else {
                int li, ri;
                cin >> li >> ri;
                --li;
                int len = ri - li;
                if (len%2 == 0) continue;
                int ci = li + len / 2;
                uint64_t lhval = stx.query(li, ci), rhval = stx.query(ci, ri), thval = lhval ^ rhval;
                ll lsum = bt.sum(li, ci), rsum = bt.sum(ci, ri);
                if (htoa.find(thval)!=htoa.end() && rsum-lsum==(ll)htoa[thval]) {
                    ++res;
                    continue;
                }
                ++ci;
                lhval = stx.query(li, ci), rhval = stx.query(ci, ri), thval = lhval ^ rhval;
                lsum = bt.sum(li, ci), rsum = bt.sum(ci, ri);
                if (htoa.find(thval)!=htoa.end() && lsum-rsum==(ll)htoa[thval]) ++res;
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
