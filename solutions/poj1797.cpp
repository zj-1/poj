// poj 1797
// 4272K 391MS G++
// dijkstra
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 1000
#define INF 0x3f3f3f3f

int t, N, M, g[MAXN][MAXN], mdis[MAXN];
bool vis[MAXN];

int dijkstra()
{
    int md, k;
    memset(vis, false, sizeof(vis));
    memset(mdis, 0xff, sizeof(mdis));
    mdis[0] = INF;
    for (int i = 0; i < N; i++) {
        md = 0; k = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && mdis[j] > md) {
                md = mdis[j]; k = j;
            }
        }
        if (k == -1) break;
        vis[k] = true;
        for (int j = 0; j < N; j++) {
            if (g[k][j] == 0) continue;
            if (mdis[k] == -1) continue;
            mdis[j] = MAX(mdis[j], MIN(mdis[k], g[k][j]));
        }
    }

    return mdis[N - 1];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int cnt = 0, u, v, d;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &N, &M);
        memset(g, 0, sizeof(g));
        while (M-- > 0) {
            scanf("%d %d %d", &u, &v, &d);
            u--, v--;
            g[u][v] = g[v][u] = d;
        }

        printf("Scenario #%d:\n%d\n\n", ++cnt, dijkstra());
    }

    return 0;
}
