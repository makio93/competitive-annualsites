// 終了後,自力解答,Set1のみ得点

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
        int e, w;
        cin >> e >> w;
        vector<vector<int>> x(e, vector<int>(w));
        rep(i, e) rep(j, w) cin >> x[i][j];
        if (w > 3) {
            cout << "Case #" << "i0" << ": " << 100 << endl;
            continue;
        }
        vector<string> tar;
        rep(i, e) {
            string tmp;
            rep(j, w) if (x[i][j] > 0) tmp += string(x[i][j], (char)('a'+j));
            sort(all(tmp));
            tar.push_back(tmp);
        }
        tar.push_back(string(""));
        vector<map<string, int>> dist((int)(tar.size())+1);
        priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<tuple<int, int, string>>> que;
        que.emplace(0, 0, string(""));
        dist[0][string("")] = 0;
        while (!que.empty()) {
            auto tti = que.top(); que.pop();
            int di = get<0>(tti), r = get<1>(tti);
            string v = get<2>(tti);
            if (dist[r][v] != di) continue;
            int ndi = di + 1;
            if (v.length() > 0) {
                string nv1 = v;
                nv1.pop_back();
                auto tmp = nv1;
                if (!tmp.empty()) sort(all(tmp));
                int nr = r;
                if (tmp == tar[r]) ++nr;
                if (dist[nr].find(nv1)==dist[nr].end() || (dist[nr].find(nv1)!=dist[nr].end()&&dist[nr][nv1]>ndi)) {
                    dist[nr][nv1] = ndi;
                    if (nr < e+1) que.emplace(ndi, nr, nv1);
                }
            }
            if (v.length() == tar[r].length()) {
                auto tmp = v;
                if (!tmp.empty()) sort(all(tmp));
                if (tmp == tar[r]) {
                    int nr = r + 1;
                    if (dist[nr].find(v)==dist[nr].end() || (dist[nr].find(v)!=dist[nr].end()&&dist[nr][v]>di)) {
                        dist[nr][v] = di;
                        que.emplace(di, nr, v);
                    }
                }
            }
            if (v.length() < tar[r].length()) {
                rep(i, w) {
                    string nv2 = v;
                    nv2.push_back((char)('a'+i));
                    auto tmp = nv2;
                    if (!tmp.empty()) sort(all(tmp));
                    int nr = r;
                    if (tmp == tar[r]) ++nr;
                    if (dist[nr].find(nv2)==dist[nr].end() || (dist[nr].find(nv2)!=dist[nr].end()&&dist[nr][nv2]>ndi)) {
                        dist[nr][nv2] = ndi;
                        que.emplace(ndi, nr, nv2);
                    }
                }
            }
        }
        cout << "Case #" << i0 << ": " << dist[e+1][string("")] << endl;
    }
    return 0;
}
