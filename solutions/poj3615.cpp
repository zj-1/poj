// poj 3615
// 704K 766MS G++
// floyd
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define INF 0x3f3f3f3f
#define MAXN 300

int N, M, T, g[MAXN][MAXN], u, v, w;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d %d %d`", &N, &M, &T) != EOF) {
        memset(g, 0x3f, sizeof(g));
        for (int i = 0; i < N; i++) g[i][i] = 0;
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &w); u--, v--;
            g[u][v] = w;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (g[i][k] == INF || g[k][j] == INF) continue;
                    g[i][j] = MIN(g[i][j], MAX(g[i][k], g[k][j]));
                }
            }
        }

        for (int i = 0; i < T; i++) {
            scanf("%d %d", &u, &v); u--, v--;
            if (g[u][v] == INF)
                printf("-1\n");
            else
                printf("%d\n", g[u][v]);
        }
    }
    return 0;
}
