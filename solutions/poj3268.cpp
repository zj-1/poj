// poj 3268
// 4276K 79MS G++
// forward and backward dijkstra
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 1000
#define INF 0x3f3f3f3f

int X, N, M, g[MAXN][MAXN], mdis[MAXN], rdis[MAXN];
bool vis[MAXN];

void dijkstra(bool flag)
{
    int md, k;
    memset(vis, false, sizeof(vis));
    memset(mdis, 0x3f, sizeof(mdis));
    mdis[X] = 0;
    for (int i = 0; i < N; i++) {
        md = INF; k = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && mdis[j] < md) {
                md = mdis[j]; k = j;
            }
        }

        if (k == -1) break;
        vis[k] = true;
        for (int j = 0; j < N; j++) {
            if (flag)
                mdis[j] = MIN(mdis[j], mdis[k] + g[k][j]);
            else
                mdis[j] = MIN(mdis[j], mdis[k] + g[j][k]);
        }
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int u, v, d, res = 0;
    scanf("%d %d %d", &N, &M, &X);
    X--;
    memset(g, 0x3f, sizeof(g));
    while (M-- > 0) {
        scanf("%d %d %d", &u, &v, &d);
        g[u - 1][v - 1] = d;
    }

    dijkstra(false);
    memcpy(rdis, mdis, sizeof(mdis));
    dijkstra(true);

    for (int i = 0; i < N; i++) res = MAX(res, mdis[i] + rdis[i]);

    printf("%d\n", res);

    return 0;
}
