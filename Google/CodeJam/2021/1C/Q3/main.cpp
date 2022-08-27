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
    rep3(i1, 1, t+1) {
        string s, e;
        cin >> s >> e;
        if (s == e) {
            cout << "Case #" << i1 << ": " << 0 << endl;
            continue;
        }
        queue<string> que;
        unordered_map<string, int> dist;
        que.push(s);
        dist[s] = 0;
        //int res = (int)(1e9);
        while (!que.empty()) {
            string v = que.front(); que.pop();
            int d = dist[v], nd = d + 1;
            /*
            int vlen = v.length(), elen = e.length();
            if ((vlen==elen&&v==e) || (vlen>elen&&v.substr(vlen-elen)==e&&v.substr(0,vlen-elen)==string(vlen-elen,'0'))) {
                res = min(res, d);
                continue;
            }
            */
            string n1 = v + "0", n2;
            bool no1 = false;
            if (v=="0" || (int)(n1.length()) > (int)(e.length())*2) {
                no1 = true;
            }
            bool fone = true;
            rep(i, (int)(v.length())) {
                if (fone&&v[i]=='1') continue;
                if (fone&&v[i]=='0') fone = false;
                if (v[i] == '1') n2 += '0';
                else n2 += '1';
            }
            if (n2.empty()) n2 = "0";
            if (!no1 && dist.find(n1)==dist.end() || dist[n1]>nd) {
                if (n1 != e) que.push(n1);
                dist[n1] = nd;
                if (n1 == e) break;
            }
            if (dist.find(n2)==dist.end() || dist[n2]>nd) {
                if (n2 != e) que.push(n2);
                dist[n2] = nd;
                if (n2 == e) break;
            }
        }
        cout << "Case #" << i1 << ": ";
        if (dist.find(e)!=dist.end()) cout << dist[e] << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
