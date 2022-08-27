#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番終了後に実装、Set1のみAC

int main(){
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int m;
        cin >> m;
        vector<int> pi(m), n(m);
        rep(i, m) cin >> pi[i] >> n[i];
        vector<int> prime;
        rep(i, m) rep(j, n[i]) {
            prime.push_back(pi[i]);
        }
        int n2 = (int)(prime.size());
        ll res = 0;
        for (ll i=1; i<(1LL<<n2)-1; ++i) {
            ll mul = -1, sum = -1;
            rep(j, n2) {
                if ((i>>j)&1) sum = (sum==-1) ? (prime[j]) : (sum + prime[j]);
                else mul = (mul==-1) ? prime[j] : (mul * prime[j]);
                //if (mul > sum) break;
            }
            if (mul == sum) res = max(res, sum);
        }
        cout << "Case #" << i1 << ": " << res << endl;
    }
    return 0;
}
