#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 復習時、解説を見てから実装、Set2まで対応、1つ目の解法、AC

const ll max_val = 100*499;

int main(){
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int m;
        cin >> m;
        vector<int> p(m), n(m);
        rep(i, m) cin >> p[i] >> n[i];
        vector<int> prime;
        rep(i, m) rep(j, n[i]) {
            prime.push_back(p[i]);
        }
        int n2 = (int)(prime.size());
        set<pair<ll, ll>> st({pair<ll,ll>({0,1})});
        rep(i, n2) {
            set<pair<ll, ll>> n_st;
            for (auto pi : st) {
                if ((ll)pi.first+prime[i] <= max_val) n_st.emplace((ll)pi.first+prime[i], pi.second);
                if ((ll)pi.second*prime[i] <= max_val) n_st.emplace(pi.first, (ll)pi.second*prime[i]);
            }
            swap(n_st, st);
        }
        ll res = 0LL;
        for (auto pi : st) if (pi.first == pi.second) res = max(res, pi.first);
        cout << "Case #" << i1 << ": " << res << endl;
    }
    return 0;
}
