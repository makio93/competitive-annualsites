// 本番,AC

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
        int n;
        cin >> n;
        vector<string> s(n);
        rep(i, n) cin >> s[i];
        vector<string> sm(26);
        vector<vector<string>> df(26);
        rep(i, n) {
            char fc = s[i].front();
            if (s[i] == string(s[i].length(), fc)) {
                sm[fc-'A'] += s[i];
            }
            else {
                df[fc-'A'].push_back(s[i]);
            }
        }
        bool res = true;
        rep(i, 26) if ((int)(df[i].size()) >= 2) {
            res = false;
            break;
        }
        if (!res) {
            cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        rep(i, 26) if (!sm[i].empty()) {
            bool ok = false;
            rep(j, 26) if (!df[j].empty() && df[j].front().back()==(char)(i+'A')) {
                ok = true;
                df[j].front() += sm[i];
                break;
            }
            if (!ok) {
                if (df[i].empty()) df[i].push_back(sm[i]);
                else {
                    string tmp = sm[i] + df[i].front();
                    df[i].front() = tmp;
                }
            }
        }
        rep(i, 26) if (!df[i].empty()) {
            bool fin = false;
            while (!fin) {
                fin = true;
                rep(j, 26) if (i!=j && !df[j].empty()) {
                    if (df[j].front().front() == df[i].front().back()) {
                        df[i].front() += df[j].front();
                        df[j].clear();
                        fin = false;
                        break;
                    }
                }
            }
        }
        string str = "";
        rep(i, 26) if (!df[i].empty()) str += df[i].front();
        vector<pair<char, int>> run;
        int m = str.length();
        run.emplace_back(str[0], 1);
        rep3(i, 1, m) {
            if (run.back().first == str[i]) run.back().second++;
            else run.emplace_back(str[i], 1);
        }
        vector<bool> used(26);
        int rlen = run.size();
        rep(i, rlen) {
            if (used[run[i].first-'A']) {
                res = false;
                break;
            }
            else used[run[i].first-'A'] = true;
        }
        if (res) cout << "Case #" << i0 << ": " << str << endl;
        else cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
    }
    return 0;
}
