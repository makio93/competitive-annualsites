// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct TrieNode {
    vector<TrieNode*> nxt;
    TrieNode() : nxt(2, nullptr) {}
    void add(string& str, int pid=0) {
        if (pid >= (int)(str.length())) return;
        rep(i, 2) if (str[pid]-'0' == i) {
            if (nxt[i] == nullptr) nxt[i] = new TrieNode();
            nxt[i]->add(str, pid+1);
        }
    }
};

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m, p;
        cin >> n >> m >> p;
        vector<string> funs(n), bans(m);
        rep(i, n) cin >> funs[i];
        rep(i, m) cin >> bans[i];
        vector<int> bcnt(p), bsum(p+1);
        rep(i, p) rep(j, n) if (funs[j][i] == '1') bcnt[i]++;
        bsum[p-1] = min(bcnt[p-1], n-bcnt[p-1]);
        repr(i, p-1) bsum[i] = bsum[i+1] + min(bcnt[i], n-bcnt[i]);
        TrieNode *root = new TrieNode();
        rep(i, m) root->add(bans[i]);
        function<int(TrieNode*,int)> search = [&](TrieNode* vnode, int id) -> int {
            if (id >= p) return (int)(1e9);
            int mval = (int)(1e9);
            rep(i, 2) {
                int bval = (i == 0) ? bcnt[id] : (n - bcnt[id]);
                if (vnode->nxt[i] == nullptr) mval = min(mval, bval+bsum[id+1]);
                else {
                    int tval = min((int)(1e9), search(vnode->nxt[i], id+1));
                    if (tval < (int)(1e9)) mval = min(mval, bval+tval);
                }
            }
            return mval;
        };
        int res = search(root, 0);
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
