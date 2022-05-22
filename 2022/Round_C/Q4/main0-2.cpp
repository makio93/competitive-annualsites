// 本番,Set1のみAC,2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
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

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        string s;
        cin >> n >> s;
        auto check = [](string& str) -> bool {
            if (str.empty()) return true;
            int li = 0, ri = str.length() - 1;
            while (li < ri) {
                if (str[li] != str[ri]) return false;
                ++li; --ri;
            }
            return true;
        };
        map<string, pair<mint, mint>> dist;
        dist[s] = { 0, 1 };
        rep(i, n) {
            map<string, pair<mint, mint>> ndist;
            int len = n - i;
            for (auto& pi : dist) {
                rep(j, len) {
                    string ns = pi.first.substr(0, j) + pi.first.substr(j+1);
                    mint nval = pi.second.first, score = pi.second.second;
                    if (check(ns)) ndist[ns].first += nval+score;
                    else ndist[ns].first += nval;
                    ndist[ns].second += score;
                }
            }
            swap(dist, ndist);
        }
        mint res = 0;
        for (auto& pi : dist) res += pi.second.first;
        rep3(i, 1, n+1) res /= i;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
