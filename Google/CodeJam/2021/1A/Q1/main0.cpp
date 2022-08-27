#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中に実装、AC

int main(){
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int n;
        cin >> n;
        vector<int> x(n);
        rep(i, n) cin >> x[i];
        int cnt = 0;
        string now = to_string(x.front());
        rep3(i, 1, n) {
            string xi = to_string(x[i]);
            if (((int)(now.length())<(int)(xi.length())) || ((int)(now.length())==(int)(xi.length())&&now<xi)) now = xi;
            else {
                string nowl = now.substr(0, (int)(xi.length()));
                if (xi < nowl) {
                    int zero = ((int)(now.length())+1) - (int)(xi.length());
                    cnt += zero;
                    string nxt = xi + string(zero, '0');
                    now = nxt;
                }
                else if (xi > nowl) {
                    int zero = (int)(now.length()) - (int)(xi.length());
                    cnt += zero;
                    string nxt = xi + string(zero, '0');
                    now = nxt;
                }
                else {
                    if ((int)(xi.length()) < (int)(now.length())) {
                        string nxt_now, nowr = now.substr((int)(xi.length()));
                        if (nowr == string((int)(nowr.length()), '9')) nxt_now += "1" + string((int)(nowr.length()), '0');
                        else {
                            int rnine = 0;
                            repr(j, (int)(nowr.length())) {
                                if (nowr[j] != '9') break;
                                ++rnine;
                            }
                            nxt_now += nowr.substr(0, (int)(nowr.length())-rnine-1);
                            nxt_now += (char)(nowr[(int)(nowr.length())-rnine-1]+1);
                            nxt_now += string(rnine, '0');
                        }
                        cnt += (int)(nxt_now.length());
                        now = xi + nxt_now;
                    }
                    else {
                        ++cnt;
                        string nxt = xi + string(1, '0');
                        now = nxt;
                    }
                }
            }
        }
        cout << "Case #" << i1 << ": " << cnt << endl;
    }
    return 0;
}
