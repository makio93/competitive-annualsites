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
        string s;
        cin >> s;
        int n = s.length();
        vector<pair<char, int>> runs;
        runs.emplace_back(s[0], 1);
        rep3(i, 1, n) {
            if (s[i] == runs.back().first) runs.back().second++;
            else runs.emplace_back(s[i], 1);
        }
        string res;
        int m = runs.size();
        rep(i, m) {
            if (i+1<m && runs[i+1].first>runs[i].first) res += string(runs[i].second*2, runs[i].first);
            else res += string(runs[i].second, runs[i].first);
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
