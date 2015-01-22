// poj 2240
// 372K 47MS G++
// floyd
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 30
#define MAXS 100

int N, M, x, y;
char u[MAXS], v[MAXS], s[MAXN][MAXS];
double g[MAXN][MAXN], w;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int cnt = 0;
    while (scanf("%d", &N) && N != 0) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] = -1.0;
            }
        }

        for (int i = 0; i < N; i++) {
            scanf("%s", s[i]);
        }

        scanf("%d", &M);
        // for (int i = 0; i < N; i++) g[i][i] = 1.0;
        while (M-- > 0) {
            scanf("%s %lf %s", u, &w, v);
            for (int i = 0; i < N; i++) {
                if (strcmp(s[i], u) == 0) x = i;
                if (strcmp(s[i], v) == 0) y = i;
            }
            g[x][y] = w;
        }

        // you can arbitrage directly @_@!
        for (int i = 0; i < N; i++) {
            // printf("%d: %lf\n", i, g[i][i]);
            if (g[i][i] > 1.0) {
                flag = false; break;
            }
        }

        if (!flag) {
            printf("Case %d: Yes\n", ++cnt);
            continue;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (g[i][k] > 0 && g[k][j] > 0)
                        g[i][j] = MAX(g[i][k] * g[k][j], g[i][j]);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            // printf("%d: %lf\n", i, g[i][i]);
            if (g[i][i] > 1.0) {
                flag = false; break;
            }
        }

        if (flag)
            printf("Case %d: No\n", ++cnt);
        else
            printf("Case %d: Yes\n", ++cnt);
    }

    return 0;
}
