// poj 2386
// 840K 0MS G++
// dfs
// easy problem
#include <cstdio>
#include <cstring>

#define MAXN 101

int m, n, res;
char data[MAXN][MAXN];
bool mk[MAXN][MAXN];
int a[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int b[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void dfs(int x, int y)
{
    int x0, y0;
    for (int i = 0; i < 8; i++) {
        x0 = x + a[i];
        y0 = y + b[i];
        if (x0 < 0 || x0 >= m || y0 < 0 || y0 >= n)
            continue;
        else if (data[x0][y0] == 'W' && !mk[x0][y0]) {
            mk[x0][y0] = true;
            dfs(x0, y0);
        }
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++)
        scanf("%s", data[i]);

    res = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (data[i][j] == 'W' && !mk[i][j]) {
                mk[i][j] = true;
                res++;
                dfs(i, j);
            }

    printf("%d\n", res);

    return 0;
}
