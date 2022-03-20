// 本番提出3,Set1のみAC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct Trie;
vector<Trie*> memo;

struct Trie {
    bool fin;
    vector<Trie*> next;
    Trie() : next(2, nullptr) {}
    void add(string& str, int id) {
        if (id >= (int)(str.length())) {
            fin = true;
            return;
        }
        if (str[id] != '?') {
            if (next[str[id]-'0'] == nullptr) {
                next[str[id]-'0'] = new Trie();
                memo.push_back(next[str[id]-'0']);
            }
            next[str[id]-'0']->add(str, id+1);
        }
        else {
            rep(i, 2) {
                if (next[i] == nullptr) {
                    next[i] = new Trie();
                    memo.push_back(next[i]);
                }
                next[i]->add(str, id+1);
            }
        }
    }
    bool search(string& str, int id) {
        if (id >= (int)(str.length())) return fin;
        if (str[id] != '?') {
            if (next[str[id]-'0'] == nullptr) return false;
            else return next[str[id]-'0']->search(str, id+1);
        }
        else {
            rep(i, 2) {
                if (next[i] == nullptr) return false;
                if (!next[i]->search(str, id+1)) return false;
            }
            return true;
        }
    }
};

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n <= 4) {
            cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
            continue;
        }
        else if (n <= 15) {
            bool res = false;
            rep(i1, (1<<n)) {
                string tar = "";
                int tval = i1;
                rep(i, n) {
                    tar.push_back((char)(tval%2+'0'));
                    tval /= 2;
                }
                bool ok = true;
                rep(li, n) {
                    rep3(ri, li+5, n+1) {
                        string tmp = tar.substr(li, ri-li), rtmp = tmp;
                        reverse(all(rtmp));
                        if (tmp == rtmp) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (!ok) continue;
                rep(i, n) {
                    if (s[i] == '?') continue;
                    else {
                        if (s[i] != tar[i]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    res = true;
                    break;
                }
            }
            if (res) cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
            else cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        }
        else {
            bool res = true;
            rep(i, n) {
                Trie *root = new Trie();
                memo.push_back(root);
                root->add(s, i);
                rep(j, n) {
                    string tmp = s.substr(i, j-i+1);
                    reverse(all(tmp));
                    if (root->search(tmp, 0)) {
                        res = false;
                        break;
                    }
                }
                int mlen = memo.size();
                rep(i, mlen) delete memo[i];
                if (!res) break;
            }
            if (res) cout << "Case #" << i0 << ": " << "POSSIBLE" << endl;
            else cout << "Case #" << i0 << ": " << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
