// poj 2472
// 436K 47MS G++
// dijkstra
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100

int n, m, a, b, p;
int g[MAXN][MAXN];
double mdis[MAXN];
bool vis[MAXN];

double dijkstra()
{
    double md; int k;
    memset(vis, false, sizeof(vis));
    memset(mdis, 0x00, sizeof(mdis));
    mdis[0] = 1.0;
    for (int i = 0; i < n; i++) {
        md = 0; k = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && mdis[j] > md) {
                md = mdis[j]; k = j;
            }
        }
        if (k == -1 || k == n - 1) break;
        vis[k] = true;
        for (int j = 0; j < n; j++) {
            mdis[j] = MAX(mdis[j], g[k][j] / 100.0 * mdis[k]);
        }
    }
    return mdis[n - 1];
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &m);
        memset(g, 0, sizeof(g));
        while (m-- > 0) {
            scanf("%d %d %d", &a, &b, &p); a--; b--;
            g[a][b] = g[b][a] = p;
        }

        // ``%.6f'' got WA !!!
        printf("%.6f percent\n", dijkstra() * 100);
    }

    return 0;
}
