// poj 1258
// 424K 16MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100

int N, res, dis[MAXN][MAXN], mdis[MAXN];
bool vis[MAXN];

int find() {
    int m = INT_MAX, k = -1;
    for (int i = 0; i < N; i++) {
        if (m > mdis[i] && !vis[i]) {
            k = i;
            m = mdis[i];
        }
    }
    return k;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &N) != EOF) {
        res = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &dis[i][j]);

        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++) mdis[i] = dis[0][i];

        vis[0] = true;
        int tmp = find();
        while (tmp != -1) {
            res += mdis[tmp];
            vis[tmp] = true;
            for (int i = 0; i < N; i++) {
                if (vis[i]) continue;
                mdis[i] = MIN(mdis[i], dis[tmp][i]);
            }
            tmp = find();
        }
        printf("%d\n", res);
    }

    return 0;
}
