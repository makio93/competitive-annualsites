// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, r, c, sr, sc;
        string s;
        cin >> n >> r >> c >> sr >> sc >> s;
        --sr; --sc;
        vector<map<int, int>> rlst(r), clst(c);
        auto add = [&](int tr, int tc) -> void {
            auto ritr = rlst[tr].upper_bound(tc);
            if (ritr==rlst[tr].end() || ritr->first>tc+1) rlst[tr][tc] = tc;
            else {
                rlst[tr][tc] = ritr->second;
                rlst[tr].erase(ritr);
            }
            ritr = rlst[tr].find(tc);
            if (ritr != rlst[tr].begin()) {
                auto litr = prev(ritr);
                if (litr->second+1 >= tc) {
                    litr->second = rlst[tr][tc];
                    rlst[tr].erase(tc);
                }
            }
            auto ditr = clst[tc].upper_bound(tr);
            if (ditr==clst[tc].end() || ditr->first>tr+1) clst[tc][tr] = tr;
            else {
                clst[tc][tr] = ditr->second;
                clst[tc].erase(ditr);
            }
            ditr = clst[tc].find(tr);
            if (ditr != clst[tc].begin()) {
                auto uitr = prev(ditr);
                if (uitr->second+1 >= tr) {
                    uitr->second = clst[tc][tr];
                    clst[tc].erase(tr);
                }
            }
        };
        int vr = sr, vc = sc;
        add(vr, vc);
        rep(i, n) {
            if (s[i] == 'N') {
                auto itr = prev(clst[vc].upper_bound(vr));
                vr = itr->first - 1;
            }
            else if (s[i] == 'S') {
                auto itr = prev(clst[vc].upper_bound(vr));
                vr = itr->second + 1;
            }
            else if (s[i] == 'W') {
                auto itr = prev(rlst[vr].upper_bound(vc));
                vc = itr->first - 1;
            }
            else {
                auto itr = prev(rlst[vr].upper_bound(vc));
                vc = itr->second + 1;
            }
            add(vr, vc);
        }
        cout << "Case #" << i0 << ": " << (vr+1) << ' ' << (vc+1) << endl;
    }
    return 0;
}
