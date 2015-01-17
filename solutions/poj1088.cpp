// poj 1088
// 596K 0MS G++
// dfs with memorization
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXL 100

struct pt {
    int x, y, h;
};

struct pt h[MAXL * MAXL];
int R, C, maxI, maxJ, maxP, res, cnt;
int data[MAXL][MAXL], dp[MAXL][MAXL];

int a[4] = { 1, -1, 0, 0 };
int b[4] = { 0, 0, 1, -1 };

int cmp(const void *a, const void *b)
{
    return ((struct pt *) a)->h - ((struct pt *) b)->h;
}

int dfs(int x, int y)
{
    if (dp[x][y] != 0)
        return dp[x][y];

    int i, x1, y1, tmp;
    for (i = 0; i < 4; i++) {
        x1 = x + a[i];
        y1 = y + b[i];
        if (!(x1 >= 0 && x1 < R && y1 >= 0 && y1 < C)) continue;
        else if (data[x1][y1] < data[x][y]) {
            tmp = dfs(x1, y1);
            dp[x][y] = MAX(dp[x][y], tmp + 1);
        }
    }

    return dp[x][y];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &R, &C);

    int i, j;
    cnt = 0;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            scanf("%d", &data[i][j]);
            h[cnt].x = i;
            h[cnt].y = j;
            h[cnt].h = data[i][j];
            cnt++;
        }
    }

    // points with lower hight are searched first
    qsort(h, R * C, sizeof(struct pt), cmp);

    res = INT_MIN;
    for (i = 0; i < cnt; i++)
        res = MAX(res, dfs(h[i].x, h[i].y));

    printf("%d\n", res + 1);

    return 0;
}
