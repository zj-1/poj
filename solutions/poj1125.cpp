// poj 1125
// 392K 0MS G++
// floyd
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define INF 0x3f3f3f3f
#define MAXN 100

int N, k, g[MAXN][MAXN], v, w;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &N) && N != 0) {
        // printf("%d\n", N);
        memset(g, 0x3f, sizeof(g));
        for (int i = 0; i < N; i++) g[i][i] = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d %d", &v, &w);
                g[i][v - 1] = w;
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (g[i][k] == INF || g[k][j] == INF) continue;
                    g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        int res = INF, tmp, t;
        for (int i = 0; i < N; i++) {
            tmp = 0;
            for (int j = 0; j < N; j++) {
                tmp = MAX(tmp, g[i][j]);
            }
            if (res > tmp) { res = tmp; t = i; }
        }

        if (res == INF)
            printf("disjoint\n");
        else
            printf("%d %d\n", t + 1, res);
    }
    return 0;
}
