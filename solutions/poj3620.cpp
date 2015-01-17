// poj 3620
// 608K 32MS G++
// dfs
// easy problem
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100

int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, 1, -1};

bool data[MAXN][MAXN];
bool vis[MAXN][MAXN];
int res, cnt, N, M, K;

void dfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (vis[x][y]) return;
    if (!data[x][y]) return;

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
    int x, y;
    scanf("%d %d %d", &N, &M, &K);
    memset(vis, false, sizeof(vis));
    memset(data, false, sizeof(data));
    while (K-- > 0) {
        scanf("%d %d", &x, &y);
        data[x - 1][y - 1] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j]) continue;
            if (!data[i][j]) continue;
            cnt = 0;
            dfs(i, j);
        }
    }

    printf("%d\n", res);
    return 0;
}
