// poj 3051
// 544K 0MS G++
// dfs
// easy problem
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXW 80
#define MAXH 1000

int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, 1, -1};

char data[MAXH][MAXW + 1];
bool vis[MAXH][MAXW];
int res, cnt, H, W;

void dfs(int x, int y)
{
    if (x < 0 || x >= H || y < 0 || y >= W) return;
    if (vis[x][y]) return;
    if (data[x][y] != '*') return;

    vis[x][y] = true;
    cnt++;
    res = MAX(res, cnt);
    for (int i = 0; i < 4; i++) {
        dfs(x + a[i], y + b[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    res = 0;
    scanf("%d %d", &W, &H);
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < H; i++) {
        scanf("%s", data[i]);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vis[i][j]) continue;
            if (data[i][j] == '.') continue;
            cnt = 0;
            dfs(i, j);
        }
    }

    printf("%d\n", res);
    return 0;
}
