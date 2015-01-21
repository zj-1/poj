// poj 1287
// 364K 32MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 50
#define INF 0x3f3f3f3f

int N, M, g[MAXN][MAXN], mdis[MAXN];
bool vis[MAXN];

int prim()
{
    int mind, k, res = 0, cnt = 0;
    vis[0] = true;
    for (int i = 0; i < N; i++) mdis[i] = g[0][i];
    while (cnt++ < N) {
        mind = INF; k = -1;
        for (int i = 0; i < N; i++) {
            if (!vis[i] && mind > mdis[i]) { mind = mdis[i]; k = i; }
        }

        if (k == -1) break;

        res += mind;
        vis[k] = true;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) mdis[i] = MIN(g[k][i], mdis[i]);
        }
    }

    return cnt == N ? res : -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int u, v, d;
    while (scanf("%d", &N) && N != 0) {
        memset(g, 0x3f, sizeof(g));
        memset(vis, false, sizeof(vis));
        scanf("%d", &M);
        while (M-- > 0) {
            scanf("%d %d %d", &u, &v, &d);
            u--, v--;
            g[u][v] = g[v][u] = MIN(d, g[u][v]);
        }

        printf("%d\n", prim());
    }
    return 0;
}
