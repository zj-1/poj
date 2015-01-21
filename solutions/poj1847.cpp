// poj 1847
// 396K 16MS G++
// dijkstra
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100
#define INF 0x3f3f3f3f

int N, A, B, mdis[MAXN], s[MAXN];
bool vis[MAXN], g[MAXN][MAXN];

int dijkstra()
{
    int md, k;
    memset(vis, false, sizeof(vis));
    memset(mdis, 0x3f, sizeof(mdis));
    mdis[A] = 0;
    for (int i = 0; i < N; i++) {
        md = INF; k = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && mdis[j] < md) {
                md = mdis[j]; k = j;
            }
        }

        if (k == -1) break;
        vis[k] = true;
        if (s[k] == -1) continue;
        for (int j = 0; j < N; j++) {
            if (!g[k][j]) continue;
            if (s[k] == j)
                mdis[j] = MIN(mdis[j], mdis[k]);
            else
                mdis[j] = MIN(mdis[j], mdis[k] + 1);
        }
    }

    return mdis[B] == INF ? -1 : mdis[B];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int x, k;
    scanf("%d %d %d", &N, &A, &B);
    A--, B--;
    memset(g, false, sizeof(g));
    memset(s, 0xff, sizeof(s));
    for (int i = 0; i < N; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            g[i][x - 1] = true;
            if (j == 0) s[i] = x - 1;
        }
    }

    printf("%d\n", dijkstra());

    return 0;
}
