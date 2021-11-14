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
        string s;
        cin >> n >> s;
        vector<tuple<char, int, int>> g(n);
        vector<set<int>> ids(10);
        rep(i, n) {
            g[i] = make_tuple( s[i], (int)((i-1>=0) ? i-1 : -1), (int)((i+1<n) ? i+1 : -1) );
            if (i+1<n) {
                if (s[i]-'0'<9 && s[i]+1==s[i+1]) ids[s[i]-'0'].insert(i);
                if (s[i]=='9' && s[i+1]=='0') ids[s[i]-'0'].insert(i); 
            }
        }
        while (1) {
            bool fin = true;
            rep(i, 10) {
                if (!ids[i].empty()) fin = false;
                char lval = (char)('0'+(i+9)%10), rval = (char)('0'+(i+2)%10), cval = rval;
                char lval2 = (char)('0'+(i+1)%10), rval2 = (char)('0'+(i+3)%10);
                while (!ids[i].empty()) {
                    auto sitr = ids[i].begin();
                    while (sitr != ids[i].end()) {
                        int sid = *sitr, lid = get<1>(g[sid]), rid = get<2>(g[sid]), rid2 = -1;
                        if (rid != -1) rid2 = get<2>(g[rid]);
                        if (lid!=-1 && get<0>(g[lid])==lval) ids[lval-'0'].erase(lid);
                        if (rid2!=-1 && get<0>(g[rid2])==rval) ids[lval2-'0'].erase(rid);
                        get<0>(g[sid]) = cval;
                        get<2>(g[sid]) = rid2;
                        get<0>(g[rid]) = '.';
                        if (rid2 != -1) get<1>(g[rid2]) = sid;
                        if (lid!=-1 && get<0>(g[lid])==lval2) ids[lval2-'0'].insert(lid);
                        if (rid2!=-1 && get<0>(g[rid2])==rval2) ids[cval-'0'].insert(sid);
                        sitr = ids[i].erase(sitr);
                    }
                }
            }
            if (fin) break;
        }
        string res;
        rep(i, n) if (get<0>(g[i]) != '.') res.push_back(get<0>(g[i]));
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
