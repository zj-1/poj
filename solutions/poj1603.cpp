// poj 1603
// 388K 0MS G++
// floyd
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 20

int N, M, t, g[MAXN][MAXN];

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &N) != EOF) {
        memset(g, 0x3f, sizeof(g));

        while (N-- > 0) {
            scanf("%d", &M); M--;
            g[0][M] = 1; g[M][0] = 1;
        }

        for (int i = 1; i < 19; i++) {
            scanf("%d", &N);
            while (N-- > 0) {
                scanf("%d", &M); M--;
                g[i][M] = 1; g[M][i] = 1;
            }
        }

        for (int k = 0; k < 20; k++) {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        int s, e;
        scanf("%d", &N);
        printf("Test Set #%d\n", ++t);
        while (N--) {
            scanf("%d %d", &s, &e);
            printf("%d to %d: %d\n", s, e, g[s - 1][e - 1]);
        }
        printf("\n");
    }

    return 0;
}
