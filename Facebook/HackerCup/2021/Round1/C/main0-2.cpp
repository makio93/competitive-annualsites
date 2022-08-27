#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const short SINF = (short)(1e4);
const ll mod = (ll)(1e9) + 7;

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        vector<int> a(n-1), b(n-1), c(n-1);
        rep(i, n-1) {
            cin >> a[i] >> b[i] >> c[i];
            a[i]--; b[i]--;
        }
        vector<unordered_map<int, pair<int, int>>> g(n);
        vector<vector<short>> dist(n, vector<short>(n, 0));
        rep(i, n) dist[i][i] = SINF;
        rep(i, n-1) {
            g[a[i]][b[i]] = { i, c[i] };
            g[b[i]][a[i]] = { i, c[i] };
            dist[a[i]][b[i]] = dist[b[i]][a[i]] = c[i];
        }
        rep(ki, n) rep(i, n) rep(j, i) {
            dist[i][j] = max({ dist[i][j], min(dist[i][ki],dist[ki][j]), min(dist[j][ki],dist[ki][i]) });
            dist[j][i] = max({ dist[j][i], min(dist[i][ki],dist[ki][j]), min(dist[j][ki],dist[ki][i]) });
        }
        ll ans = 1;
        rep(i, n-1) {
            unordered_set<int> ast;
            vector<bool> visited(n);
            ll sum = 0;
            function<void(int,int,unordered_set<int>&)> dfs = [&](int v, int p, unordered_set<int>& st) -> void {
                for (auto si : st) sum = (sum + dist[v][si]) % mod;
                st.insert(v);
                visited[v] = true;
                for (auto pi : g[v]) if (pi.first != p) {
                    if (!visited[pi.first]) dfs(pi.first, v, st);
                }
            };
            dfs(a[i], b[i], ast);
            ast.clear();
            dfs(b[i], a[i], ast);
            ans = ans * sum % mod;
        }
        cout << "Case #" << i0 << ": " << ans << endl;
    }
    return 0;
}
