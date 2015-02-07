// poj 1975
// 396K 16MS G++
// floyd
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 99

int N, M, t, u, v, res, cnt1, cnt2;
bool g[MAXN][MAXN];

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &N, &M);
        memset(g, false, sizeof(g)); res = 0;

        while (M-- > 0) {
            scanf("%d %d", &u, &v);
            g[u - 1][v - 1] = true;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            cnt1 = cnt2 = 0;
            for (int j = 0; j < N; j++) {
                if (g[i][j]) cnt1++;
                if (g[j][i]) cnt2++;
            }
            if (cnt1 > (N / 2) || cnt2 > (N / 2)) res++;
        }
        printf("%d\n", res);
    }

    return 0;
}
