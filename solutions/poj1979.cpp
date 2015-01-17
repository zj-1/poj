// poj 1979
// 384K 16MS G++
// dfs
// easy problem
#include <cstdio>
#include <cstring>

#define MAXN 20

int row, col, ans;
bool data[MAXN][MAXN], rec[MAXN][MAXN];
int a[4] = { 0, 1, -1, 0 };
int b[4] = { -1, 0, 0, 1 };

bool ok(int r, int c)
{
    if (r >= 0 && r < row && c >= 0 && c < col)
        return true;
    else
        return false;
}

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++) {
        int r = x + a[i];
        int c = y + b[i];
        if (ok(r, c) && !rec[r][c] && data[r][c]) {
            rec[r][c] = true;
            ans++;
            dfs(r, c);
        }
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int i, j, sr, sc;
    char c;
    while (true) {
        scanf("%d %d", &col, &row);
        if (row == 0 && col == 0)
            break;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (j == 0)
                    scanf("\n%c", &c);
                else
                    scanf("%c", &c);
                if (c == '.')
                    data[i][j] = true;
                else if (c == '#')
                    data[i][j] = false;
                else {
                    data[i][j] = true;
                    sr = i;
                    sc = j;
                }
            }
        }
        memset(rec, false, sizeof(rec));
        rec[sr][sc] = true;
        ans = 1;
        dfs(sr, sc);
        printf("%d\n", ans);
    }
    return 0;
}
