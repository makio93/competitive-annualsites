// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

const ll mod = (ll)(1e9) + 7;

int mpow(ll a, int b, int m) {
    ll p = a, res = 1;
    while (b) {
        if (b%2) res = res * p % m;
        p = p * p % m;
        b /= 2;
    }
    return (int)res;
}

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int a, b, k;
        ll n;
        cin >> a >> b >> n >> k;
        vector<ll> acnt(k, -1), bcnt(k, -1);
        auto search = [&](vector<ll>& mcnt, int aval) -> int {
            int kval = 0, rlen = -1, rval = -1;
            for (int i=1; (ll)i<=n; ++i) {
                kval = mpow(i, aval, k);
                if (mcnt[kval] != -1) {
                    rlen = i - mcnt[kval];
                    rval = mcnt[kval];
                    break;
                }
                mcnt[kval] = i;
            }
            rep(i, k) {
                if (mcnt[i] != -1) mcnt[i] = 1;
                else mcnt[i] = 0;
            }
            if (rlen != -1) {
                ll rcnt = (n - (rval - 1)) / rlen, mval = (n - (rval - 1)) % rlen, tval = kval;
                int tcnt = 1;
                do {
                    mcnt[kval] = rcnt;
                    if (tcnt <= mval) mcnt[kval]++;
                    ++rval; ++tcnt;
                    kval = mpow(rval, aval, k);
                } while (kval != tval);
            }
            return rlen;
        };
        int arlen = search(acnt, a), brlen = search(bcnt, b);
        ll abrlen = lcm(arlen, brlen);
        vector<ll> abcnt(k, 0), mabcnt(k, 0), rabcnt(k, 0);
        int abkval = 0;
        for (int i=1; (ll)i<=n; ++i) {
            abkval = (mpow(i, a, k) + mpow(i, b, k)) % k;
            abcnt[abkval]++;
            if (i >= abrlen*2) break;
            if (i >= abrlen) mabcnt[abkval]++;
            if (i%abrlen <= n%abrlen) rabcnt[abkval]++;
        }
        if (abrlen*2 > n) {
            ll rcnt = n / abrlen - 2;
            rep(i, k) abcnt[i] = (abcnt[i] + mabcnt[i] * rcnt + rabcnt[i]) % mod;
        }
        ll res = acnt[0] % mod * bcnt[0] % mod;
        rep3(i, 1, k) res = (res + acnt[i] % mod * (bcnt[k-i] % mod)) % mod;
        res = (res - abcnt[0] % mod + mod) % mod;
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
