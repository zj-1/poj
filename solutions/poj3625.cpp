// poj 3625
// 8212K 141MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 1000

int N, M, a, b, x[MAXN], y[MAXN];
long long dis[MAXN][MAXN], mdis[MAXN];
double res;
bool vis[MAXN];

int find()
{
    long long m = LLONG_MAX;
    int k = -1;
    for (int i = 0; i < N; i++) {
        if (m > mdis[i] && !vis[i]) {
            k = i;
            m = mdis[i];
        }
    }
    return k;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    res = 0.0;
    memset(vis, false, sizeof(vis));
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", x + i, y + i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dis[i][j] = dis[j][i] = ((long long) x[i] - x[j]) * (x[i] - x[j])
                + ((long long) y[i] - y[j]) * (y[i] - y[j]);
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        dis[a - 1][b - 1] = dis[b - 1][a - 1] = -1;
    }

    for (int i = 0; i < N; i++) mdis[i] = dis[0][i];
    vis[0] = true;
    int tmp = find();
    while (tmp != -1) {
        if (mdis[tmp] != -1) res += sqrt(mdis[tmp]);
        vis[tmp] = true;
        for (int i = 0; i < N; i++) {
            if (vis[i]) continue;
            mdis[i] = MIN(mdis[i], dis[tmp][i]);
        }
        tmp = find();
    }

    printf("%.2f\n", res);

    return 0;
}
