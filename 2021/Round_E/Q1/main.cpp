#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int t;
    cin >> t;
    rep3(i0, 1, t+1) {
        string s;
        cin >> s;
        int n = s.length();
        unordered_map<char, int> ccnt;
        for (char c : s) ccnt[c]++;
        vector<pair<int, char>> run;
        for (auto p : ccnt) run.emplace_back(p.second, p.first);
        sort(run.rbegin(), run.rend());
        int diff = run.front().first;
        string fr, to;
        for (auto p : run) fr += string(p.first, p.second);
        to = fr.substr(diff) + fr.substr(0, diff);
        unordered_map<char, queue<char>> dict;
        bool ok = true;
        rep(i, n) {
            dict[fr[i]].push(to[i]);
            if (fr[i] == to[i]) ok = false;
        }
        string res;
        if (ok) {
            rep(i, n) {
                res += (char)(dict[s[i]].front());
                dict[s[i]].pop();
            }
        }
        else res = "IMPOSSIBLE";
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
