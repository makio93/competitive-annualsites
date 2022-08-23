// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const vector<string> ys = { "Alice", "Bob", "nobody" };
const vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        string k;
        cin >> k;
        int rid = 1;
        if (find(all(vowels), tolower(k.back())) != vowels.end()) rid = 0;
        else if (tolower(k.back()) == 'y') rid = 2;
        cout << "Case #" << i0 << ": " << k << " is ruled by " << ys[rid] << "." << endl;
    }
    return 0;
}
