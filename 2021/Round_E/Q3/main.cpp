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
        int n, m;
        cin >> n >> m;
        vector<string> r(n);
        rep(i, n) cin >> r[i];
        unordered_map<int, vector<int>> g;
        vector<vector<bool>> visited(n*m, vector<bool>(2));
        rep(i, n) rep(j, m) if (r[i][j] != '#') {
            const vector<vector<int>> dy = { { -1, 1 }, { 0, 0 } }, dx = { { 0, 0 }, { -1, 1 } };
            const vector<int> dy2 = { 1, 0 }, dx2 = { 0, 1 };
            rep(i2, 2) if (!visited[i*m+j][i2]) {
                visited[i*m+j][i2] = true;
                vector<int> cnt(2);
                rep(j2, 2) {
                    int ny = i + dy[i2][j2], nx = j + dx[i2][j2];
                    if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                    if (r[ny][nx] != '#') cnt[j2]++;
                }
                if (cnt[0]==0 && cnt[1]==1) {
                    int len = 0, ypos = i, xpos = j;
                    while (ypos>=0 && ypos<n && xpos>=0 && xpos<m) {
                        if (r[ypos][xpos] == '#') break;
                        ++len;
                        visited[ypos*m+xpos][i2] = true;
                        ypos += dy2[i2]; xpos += dx2[i2];
                    }
                    for (int j2=0; j2<len-j2-1; ++j2) {
                        int fri = i + dy2[i2] * j2, frj = j + dx2[i2] * j2;
                        int toi = i + dy2[i2] * (len-j2-1), toj = j + dx2[i2] * (len-j2-1); 
                        g[fri*m+frj].push_back(toi*m+toj);
                        g[toi*m+toj].push_back(fri*m+frj);
                    }
                }
            }
        }
        unordered_set<int> visited2;
        int res = 0;
        queue<int> rest;
        for (auto p : g) rest.push(p.first);
        int tval = 0, mlim = rest.size();
        while (!rest.empty() && tval<mlim) {
            int pval = rest.front(); rest.pop();
            if (visited2.find(pval) != visited2.end()) continue;
            int ypos = pval / m, xpos = pval % m;
            if (!isupper(r[ypos][xpos])) {
                rest.push(pval);
                ++tval;
                continue;
            }
            visited2.insert(pval);
            tval = 0;
            int nc = r[ypos][xpos];
            queue<int> que;
            que.push(pval);
            while (!que.empty()) {
                int pos = que.front(); que.pop();
                for (int ti : g[pos]) if (visited2.find(ti) == visited2.end()) {
                    int ny = ti / m, nx = ti % m;
                    if (r[ny][nx] == '.') {
                        r[ny][nx] = nc;
                        ++res;
                        que.push(ti);
                    }
                }
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
        rep(i, n) cout << r[i] << endl;
    }
    return 0;
}
