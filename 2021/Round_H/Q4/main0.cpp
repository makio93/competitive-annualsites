#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,WA

const ll mod = (ll)(1e9) + 7;
const ll mul = (ll)(1e6);

struct mint {
    ll x;
    mint(ll x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

vector<vector<int>> g;
vector<ll> a, b;
map<tuple<int, int, bool>, mint> memo;
vector<int> depth;

void dfs0(int v=0, int d=0) {
    depth[v] = d;
    for (int ti : g[v]) dfs0(ti, d+1);
}

mint dfs(int tar, int v=0, bool stat=true) {
    if (memo.find({tar, v, stat}) != memo.end()) return memo[{tar, v, stat}];
    mint res = 0;
    if (v == tar) {
        res = (stat) ? (mint(a[v])/mul) : (mint(b[v])/mul);
        return (memo[{tar, v, stat}] = res);
    }
    else {
        mint val1 = 0, val2 = 0;
        for (int ti : g[v]) val1 += dfs(tar, ti, true);
        for (int ti : g[v]) val2 += dfs(tar, ti, false);
        if (stat) {
            val1 *= mint(a[v])/mul;
            val2 *= (mint(mul)-mint(a[v]))/mul;
        }
        else {
            val1 *= mint(b[v])/mul;
            val2 *= (mint(mul)-mint(b[v]))/mul;
        }
        return (memo[{tar, v, stat}] = val1 + val2);
    }
}

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, q;
        cin >> n >> q;
        g = vector<vector<int>>(n);
        a = vector<ll>(n);
        b = vector<ll>(n);
        memo = map<tuple<int, int, bool>, mint>();
        cin >> a[0];
        b[0] = 0;
        rep3(i, 1, n) {
            int pi;
            cin >> pi >> a[i] >> b[i];
            --pi;
            g[pi].push_back(i);
        }
        depth = vector<int>(n, -1);
        dfs0();
        vector<ll> res(q);
        rep(i, q) {
            int ui, vi;
            cin >> ui >> vi;
            --ui; --vi;
            mint ret = dfs(ui) * dfs(vi);
            res[i] = ret.x;
        }
        cout << "Case #" << i0 << ":";
        rep(i, q) cout << ' ' << res[i];
        cout << endl;
    }
    return 0;
}
