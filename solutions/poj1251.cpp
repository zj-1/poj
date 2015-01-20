// poj 1251
// 388K 0MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 27

int N, res, dis[MAXN][MAXN], mdis[MAXN];
bool vis[MAXN];

int find() {
    int m = INT_MAX, k = -1;
    for (int i = 0; i < N; i++) {
        if (m > mdis[i] && !vis[i] && mdis[i] > 0) {
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
    while (scanf("%d", &N) && N != 0) {

        memset(dis, 0xff, sizeof(dis));
        int tx, ty, k, tt;
        char c[3];
        for (int i = 0; i < N - 1; i++) {
            scanf("%s %d", c, &k);
            tx = c[0] - 'A';
            while(k-- > 0) {
                scanf("%s %d", c, &tt);
                ty = c[0] - 'A';
                dis[tx][ty] = dis[ty][tx] = tt;
            }
        }

        res = 0;

        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++) mdis[i] = dis[0][i];

        vis[0] = true;
        int tmp = find();
        while (tmp != -1) {
            res += mdis[tmp];
            vis[tmp] = true;
            for (int i = 0; i < N; i++) {
                if (vis[i]) continue;
                if (dis[tmp][i] <= 0) continue;
                if (mdis[i] == -1)
                    mdis[i] = dis[tmp][i];
                else
                    mdis[i] = MIN(mdis[i], dis[tmp][i]);
            }
            tmp = find();
        }
        printf("%d\n", res);
    }

    return 0;
}
