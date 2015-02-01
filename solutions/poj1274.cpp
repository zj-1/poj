// poj 1274
// 392K 16MS G++
// bipartite matching
#include <cstdio>
#include <cstring>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 200
#define MAXM 200

int N, M, mch[MAXM];
bool vis[MAXN], g[MAXN][MAXM];

bool dfs(int v)
{
    for (int u = 0; u < M; u++) {
        if (!g[v][u]) continue;
        int w = mch[u];
        if (vis[u]) continue;
        vis[u] = true;
        if (w == -1 || dfs(w)) {
            mch[u] = v; return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int n, v;
    while (scanf("%d %d", &N, &M) != EOF) {
        memset(g, 0, sizeof(g));
        for (int i = 0; i < N; i++) {
            scanf("%d", &n);
            while (n-- > 0) {
                scanf("%d", &v);
                g[i][v - 1] = true;
            }
        }

        int res = 0;
        memset(mch, 0xff, sizeof(mch));
        for (int i = 0; i < N; i++) {
            memset(vis, false, sizeof(vis));
            if (dfs(i)) res++;
        }

        printf("%d\n", res);
    }

    return 0;
}
