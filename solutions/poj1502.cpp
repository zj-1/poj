// poj 1502
// 400K 0MS G++
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

int N, g[MAXN][MAXN];
char s[20];

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < N; i++) {
        g[i][i] = 0;
        for (int j = 0; j < i; j++) {
            scanf("%s", s);
            if (strcmp(s, "x") != 0)
                g[i][j] = g[j][i] = atoi(s);;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int res = -1;
    for (int i = 0; i < N; i++) {
        res = MAX(res, g[0][i]);
    }

    printf("%d\n", res);

    return 0;
}
