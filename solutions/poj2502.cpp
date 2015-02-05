// poj 2502
// 676K 125MS G++
// floyd
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 202

int x[MAXN], y[MAXN];
int N, a, b, k;
double g[MAXN][MAXN];

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    // memset(g, 0, sizeof(g));
    scanf("%d %d %d %d", x, y, x + 1, y + 1);
    N = 2;
    while (scanf("%d %d", &a, &b) != EOF) {
        k = 0;
        while (a != -1 && b != -1) {
            x[N + k] = a; y[N + k] = b; k++;
            scanf("%d %d", &a, &b);
        }
        for (int i = 0; i < k - 1; i++) {
            int tx = N + i, ty = N + i + 1;
            g[tx][ty] = g[ty][tx] = sqrt((x[tx] - x[ty]) * (x[tx] - x[ty])
                    + (y[tx] - y[ty]) * (y[tx] - y[ty])) * 0.09;
        }
        N += k;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j] > 0) continue;
            g[i][j] = g[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j])
                    + (y[i] - y[j]) * (y[i] - y[j])) * 0.36;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    printf("%d\n", (int) (g[0][1] / 60.0 + 0.5));

    return 0;
}
