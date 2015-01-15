// poj 1154
// 400K 32MS G++
// easy problem
// dfs
#include <cstdio>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MAXN 21

int m, n, res;
char data[MAXN][MAXN];
bool mk[26];
int a[4] = { 0, 0, -1, 1 };
int b[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int cnt)
{
    int x0, y0;
    res = MAX(res, cnt);
    for (int i = 0; i < 4; i++) {
        x0 = x + a[i];
        y0 = y + b[i];
        if (x0 < 0 || x0 >= m || y0 < 0 || y0 >= n)
            continue;
        else if (!mk[data[x0][y0] - 'A']) {
            mk[data[x0][y0] - 'A'] = true;
            dfs(x0, y0, cnt + 1);
            mk[data[x0][y0] - 'A'] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
        scanf("%s", data[i]);

    mk[data[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    printf("%d\n", res);

    return 0;
}
