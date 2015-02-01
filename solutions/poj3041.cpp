// poj 3041
// 1136K 16MS G++
// bipartite matching
#include <cstdio>
#include <cstring>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 500

int N, K, R, C, g[MAXN][MAXN], dg[MAXN], mch[MAXN];
bool vis[MAXN];

bool dfs(int v)
{
    for (int i = 0; i < dg[v]; i++) {
        int u = g[v][i], w = mch[u];
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

    scanf("%d %d", &N, &K);
    memset(dg, 0, sizeof(dg));
    while (K-- > 0) {
        scanf("%d %d", &R, &C); R--; C--;
        g[R][dg[R]++] = C;
    }

    int res = 0;
    memset(mch, 0xff, sizeof(mch));
    for (int i = 0; i < N; i++) {
        memset(vis, false, sizeof(vis));
        if (dfs(i)) res++;
    }

    printf("%d\n", res);

    return 0;
}
