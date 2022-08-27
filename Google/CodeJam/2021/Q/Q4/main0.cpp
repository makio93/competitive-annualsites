#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中に実装、Set2までAC

int query(int l) {
    rep(i, 3) printf("%d%c", l+i, (i<2?' ':'\n'));
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

int query(vector<int> lst) {
    rep(i, 3) printf("%d%c", lst[i], (i<2?' ':'\n'));
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

vector<int> merge(int l, int r) {
    int ni = r - l + 1;
    vector<int> resi;
    if (ni < 3) {
        rep3(i, l, r+1) resi.push_back(i);
        return resi;
    }
    else if (ni == 3) {
        int c = query(vector<int>{l,l+1,l+2});
        resi = vector<int>(3);
        resi[1] = c;
        int cnt = 0;
        rep3(i, l, r+1) if (i != c) {
            if (cnt == 1) resi[2] = i;
            else resi[0] = i;
            ++cnt;
        }
        return resi;
    }
    else {
        bool rev = false;
        pair<vector<int>, vector<int>> resi2 = { merge(l,(l+r)/2), merge((l+r)/2+1,r) };
        int c = query((vector<int>){resi2.first[0],resi2.first[1],resi2.second.front()});
        if (c==resi2.second.front()) {
            int c2 = query((vector<int>){resi2.first.front(),resi2.second.front(),resi2.second.back()});
            if (c2 != resi2.second.front()) rev = true;
        }
        else {
            if (c == resi2.first[0]) {
                int c2 = query((vector<int>){resi2.first[0],resi2.second.front(),resi2.second.back()});
                if (c2 == resi2.second.front()) rev = true;
            }
            else {
                int c2 = query((vector<int>){resi2.first[1],resi2.second.front(),resi2.second.back()});
                if (c2 != resi2.second.front()) rev = true;
            }
        }
        if (rev) reverse(all(resi2.second));
        int id1 = 0, id2 = 0;
        while (id1+1<(int)(resi2.first.size()) && id2<(int)(resi2.second.size())) {
            int c2 = query((vector<int>){resi2.first[id1],resi2.first[id1+1],resi2.second[id2]});
            if (c2 == resi2.first[id1]) {
                resi.push_back(resi2.second[id2]);
                ++id2;
            }
            else if (c2 == resi2.second[id2]) {
                resi.push_back(resi2.first[id1]);
                ++id1;
            }
            else {
                resi.push_back(resi2.first[id1]);
                resi.push_back(resi2.first[id1+1]);
                id1 += 2;
            }
        }
        if (id2 >= (int)(resi2.second.size())) {
            while (id1 < (int)(resi2.first.size())) {
                resi.push_back(resi2.first[id1]);
                ++id1;
            }
        }
        if (id1==(int)(resi2.first.size())-1 && id2<(int)(resi2.second.size())) {
            while (id2<(int)(resi2.second.size())) {
                int c2 = query((vector<int>){resi2.first[id1-1],resi2.first[id1],resi2.second[id2]});
                if (c2 == resi2.second[id2]) {
                    resi.push_back(resi2.second[id2]);
                    ++id2;
                }
                else {
                    resi.push_back(resi2.first[id1]);
                    ++id1;
                    break;
                }
            }
        }
        while (id1<(int)(resi2.first.size())) {
            resi.push_back(resi2.first[id1]);
            ++id1;
        }
        while (id2<(int)(resi2.second.size())) {
            resi.push_back(resi2.second[id2]);
            ++id2;
        }
        return resi;
    }
}

int main(){
    int t, n, q;
    cin >> t >> n >> q;
    rep3(i1, 1, t+1) {
        // int qi = q / t;
        vector<int> ans = merge(1, n);
        rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
        cout.flush();
        int res;
        cin >> res;
        if (res != 1) exit(0);
    }
    return 0;
}
