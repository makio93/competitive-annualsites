#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const string vowels = "AEIOU";

int main() {
    int t;
    cin >> t;
    vector<string> cset = { vowels, "" };
    for (char ci='A'; ci<='Z'; ++ci) if (vowels.find(ci) == string::npos) cset[1] += ci;
    rep3(i0, 1, t+1) {
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> ccnt(2);
        rep(i, 2) ccnt[i] = vector<int>(cset[i].size());
        for (char ci : s) rep(i, 2) if (cset[i].find(ci) != string::npos) ccnt[i][cset[i].find(ci)]++;
        vector<int> csum(2);
        rep(i, 2) for (int val : ccnt[i]) csum[i] += val;
        rep(i, 2) sort(ccnt[i].rbegin(), ccnt[i].rend());
        int res = (int)(1e9);
        rep(i, 2) res = min(res, (csum[i]-ccnt[i].front())*2+csum[(i+1)%2]);
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
