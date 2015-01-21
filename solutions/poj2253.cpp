// poj 2253
// 524K 0MS G++
// dijkstra
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 200
#define INF 0x3f3f3f3f

int N, x[MAXN], y[MAXN], dis[MAXN][MAXN], mdis[MAXN];
bool vis[MAXN];

double dijkstra()
{
    int md, k;
    memset(vis, false, sizeof(vis));
    memset(mdis, 0x3f, sizeof(mdis));
    mdis[0] = 0;
    for (int i = 0; i < N; i++) {
        md = INF; k = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && mdis[j] < md) {
                md = mdis[j]; k = j;
            }
        }
        // printf("k = %d\n", k);
        if (k == -1) break;
        vis[k] = true;
        for (int j = 0; j < N; j++) {
            mdis[j] = MIN(mdis[j], MAX(mdis[k], dis[k][j]));
        }
    }

    // for (int i = 0; i < N; i++) {
    //     printf("%d\n", mdis[i]);
    // }

    return sqrt(mdis[1] * 1.0);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int cnt = 0;
    while (scanf("%d", &N) && N != 0) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d", x + i, y + i);
        }

        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                dis[i][j] = dis[j][i] = (x[i] - x[j]) * (x[i] - x[j])
                    + (y[i] - y[j]) * (y[i] - y[j]);
            }
        }

        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++cnt, dijkstra());
    }

    return 0;
}
