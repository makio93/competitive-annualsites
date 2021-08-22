#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        int n;
        cin >> n;
        vector<ll> cards(n);
        rep(i, n) cards[i] = i+1;
        ll sum = 0, ncnt = 0;
        do {
            ll score = 1;
            ll pval = cards.front();
            rep3(i, 1, n) if (cards[i] > pval) {
                pval = max(pval, cards[i]);
                ++score;
            }
            sum += score; ++ncnt;
        } while (next_permutation(all(cards)));
        printf("Case #%d: %.10f\n", i0, ((double)sum/ncnt));
    }
    return 0;
}
