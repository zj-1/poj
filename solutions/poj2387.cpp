// poj 2387
// 4272K 63MS G++
// dijkstra
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

#define MAXN 1000
#define INF 0x3f3f3f3f

int g[MAXN][MAXN], mdis[MAXN], n, m;
bool vis[MAXN];

void dijkstra()
{
    int min, t;

    for (int i = 0; i < n; i++) mdis[i] = g[0][i];

    while (true) {
        min = INF;
        for (int i = 1; i < n; i++) {
            if (!vis[i] && mdis[i] < min) {
                min = mdis[i];
                t = i;
            }
        }

        if (min == INF) break;

        vis[t] = true;
        for (int i = 1; i < n; i++) {
            mdis[i] = MIN(mdis[t] + g[t][i], mdis[i]);
        }
    }
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int a, b, d;
    scanf("%d %d", &m, &n);
    memset(g, 0x3f, sizeof(g));

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &d);
        a--, b--;
        g[a][b] = g[b][a] = MIN(d, g[a][b]);
    }

    dijkstra();

    printf("%d\n", mdis[n - 1]);
    return 0;
}
