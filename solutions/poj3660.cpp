// poj 3660
// 364K 63MS G++
// floyd
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100

int N, M, u, v;
bool g[MAXN][MAXN];

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    memset(g, false, sizeof(g));

    while (M-- > 0) {
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u][v] = true;
    }

    for (int i = 0; i < N; i++) g[i][i] = true;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!g[i][j]) g[i][j] = g[i][k] & g[k][j];
            }
        }
    }

    int res = 0, cnt;
    for (int i = 0; i < N; i++) {
        cnt = 0;
        for (int j = 0; j < N; j++) {
            if (g[i][j]) cnt++;
            if (g[j][i]) cnt++;
        }
        if (cnt == N + 1) res++;
    }

    printf("%d\n", res);

    return 0;
}
