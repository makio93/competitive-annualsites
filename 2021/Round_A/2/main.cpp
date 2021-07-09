#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番提出コード（のちに少し手直し）/AC

int main(){
    int t;
    cin >> t;
    rep3(i1, 1, t+1) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c));
        rep(i, r) rep(j, c) cin >> grid[i][j];
        vector<vector<vector<int>>> len(4, vector<vector<int>>(r+2, vector<int>(c+2)));
        const vector<vector<int>> dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        rep(i2, 4) {
            if (i2/2==0) {
                rep3(i, 1, r+1) {
                    int y = i, x = (i2%2==0) ? 1 : c;
                    int py = y - dir[i2][0], px = x - dir[i2][1];
                    rep3(j, 1, c+1) {
                        if (grid[y-1][x-1] == 1) len[i2][y][x] = len[i2][py][px] + 1;
                        else len[i2][y][x] = 0;
                        py = y; px = x;
                        y += dir[i2][0]; x += dir[i2][1];
                    }
                }
            }
            else {
                rep3(i, 1, c+1) {
                    int y = (i2%2==0) ? 1 : r, x = i;
                    int py = y - dir[i2][0], px = x - dir[i2][1];
                    rep3(j, 1, r+1) {
                        if (grid[y-1][x-1] == 1) len[i2][y][x] = len[i2][py][px] + 1;
                        else len[i2][y][x] = 0;
                        py = y; px = x;
                        y += dir[i2][0]; x += dir[i2][1];
                    }
                }
            }
        }
        int cnt = 0;
        rep(i2, 4) {
            vector<int> tdir;
            if (i2/2 == 0) tdir = { 2, 3 };
            else tdir = { 0, 1 };
            rep3(i, 1, r+1) rep3(j, 1, c+1) {
                if (len[i2][i][j] / 2 >= 2){
                    rep(j2, 2) {
                        if (len[tdir[j2]][i][j] >= 2) cnt += min(len[i2][i][j]/2, len[tdir[j2]][i][j]) - 1;
                    }
                }
            }
        }
        cout << "Case #" << i1 << ": " << cnt << endl;
    }
    return 0;
}
