// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0) : n(n), d(n+1) {}
    void add(int i, T x=1) {
        for (i++; i<=n; i+=i&-i) {
            d[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i-=i&-i) {
            x += d[i];
        }
        return x;
    }
    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

int main() {
    int t0;
    cin >> t0;
    rep3(i0, 1, t0+1) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        rep(i, n) {
            cin >> a[i];
            a[i]--;
        }
        vector<BIT<int>> asums(3, BIT<int>(n+1));
        rep(i, n) asums[a[i]].add(i);
        ll res = 0;
        rep(i, m) {
            int xi, yi, zi;
            cin >> xi >> yi >> zi;
            --xi; --yi;
            asums[a[xi]].add(xi, -1);
            asums[yi].add(xi);
            vector<int> lcnt(3), rcnt(3);
            rep(j, 3) {
                lcnt[j] = asums[j].sum(0, zi);
                rcnt[j] = asums[j].sum(zi, n);
            }
            int lsum = 0, rsum = 0;
            rep(j, 3) {
                lsum += lcnt[j] * (j+1);
                rsum += rcnt[j] * (j+1);
            }
            if ((rsum-lsum)%2 == 1) {
                res += -1;
                continue;
            }
            if (lsum == rsum) continue;
            if (rsum > lsum) {
                int tres1 = INF;
                {
                    int tres = 0;
                    int scnt = (rsum - lsum) / 2;
                    int dval = min(scnt/2, min(rcnt[2], lcnt[0]));
                    scnt -= dval * 2;
                    lcnt[2] += dval;
                    rcnt[0] += dval;
                    lcnt[0] -= dval;
                    rcnt[2] -= dval;
                    tres += dval;
                    int dval2 = min(scnt, min(rcnt[1], lcnt[0]));
                    scnt -= dval2;
                    lcnt[1] += dval2;
                    rcnt[0] += dval2;
                    lcnt[0] -= dval2;
                    rcnt[1] -= dval2;
                    tres += dval2;
                    int dval3 = min(scnt, min(rcnt[2], lcnt[1]));
                    scnt -= dval3;
                    lcnt[2] += dval3;
                    rcnt[1] += dval3;
                    lcnt[1] -= dval3;
                    rcnt[2] -= dval3;
                    tres += dval3;
                    if (scnt == 0) {
                        tres1 = min(tres1, tres);
                    }
                }
                 {
                    int tres = 0;
                    int scnt = (rsum - lsum) / 2;
                    int dval = min(scnt/2+1, min(rcnt[2], lcnt[0]));
                    scnt -= dval * 2;
                    lcnt[2] += dval;
                    rcnt[0] += dval;
                    lcnt[0] -= dval;
                    rcnt[2] -= dval;
                    tres += dval;
                    if ((rcnt[0]>0&&lcnt[1]>0) || (rcnt[0]>0&&lcnt[2]>0) || (rcnt[1]>0&&lcnt[2])) {
                        ++tres;
                        --scnt;
                    }
                    if (scnt == 0) {
                        tres1 = min(tres1, tres);
                    }
                }
                if (tres1 == INF) res += -1;
                else res += tres1;
            }
            else if (rsum < lsum) {
                int tres1 = INF;
                {
                    int tres = 0;
                    int scnt = (lsum - rsum) / 2;
                    int dval = min(scnt/2, min(lcnt[2], rcnt[0]));
                    scnt -= dval * 2;
                    rcnt[2] += dval;
                    lcnt[0] += dval;
                    rcnt[0] -= dval;
                    lcnt[2] -= dval;
                    tres += dval;
                    int dval2 = min(scnt, min(lcnt[1], rcnt[0]));
                    scnt -= dval2;
                    rcnt[1] += dval2;
                    lcnt[0] += dval2;
                    rcnt[0] -= dval2;
                    lcnt[1] -= dval2;
                    tres += dval2;
                    int dval3 = min(scnt, min(lcnt[2], rcnt[1]));
                    scnt -= dval3;
                    rcnt[2] += dval3;
                    lcnt[1] += dval3;
                    rcnt[1] -= dval3;
                    lcnt[2] -= dval3;
                    tres += dval3;
                    if (scnt == 0) {
                        tres1 = min(tres1, tres);
                    }
                }
                 {
                    int tres = 0;
                    int scnt = (lsum - rsum) / 2;
                    int dval = min(scnt/2+1, min(lcnt[2], rcnt[0]));
                    scnt -= dval * 2;
                    rcnt[2] += dval;
                    lcnt[0] += dval;
                    rcnt[0] -= dval;
                    lcnt[2] -= dval;
                    tres += dval;
                    if ((lcnt[0]>0&&rcnt[1]>0) || (lcnt[0]>0&&rcnt[2]>0) || (lcnt[1]>0&&rcnt[2])) {
                        ++tres;
                        --scnt;
                    }
                    if (scnt == 0) {
                        tres1 = min(tres1, tres);
                    }
                }
                if (tres1 == INF) res += -1;
                else res += tres1;
            }
        }
        cout << "Case #" << i0 << ": " << res << endl;
    }
    return 0;
}
