// poj 1789
// 16044K 641MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 2000
#define MAXM 7

int N, a, b, dis[MAXN][MAXN], mdis[MAXN], res;
bool vis[MAXN];
char data[MAXN][MAXM + 1];

int find()
{
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
    while (scanf("%d", &N) && N != 0) {
        res = 0;
        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));

        for (int i = 0; i < N; i++) {
            scanf("%s", &data[i][0]);
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = 0; k < MAXM; k++) {
                    if (data[i][k] != data[j][k]) {
                        dis[i][j]++;
                        dis[j][i]++;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) mdis[i] = dis[0][i];
        vis[0] = true;
        int tmp = find();
        while (tmp != -1) {
            res += mdis[tmp];
            vis[tmp] = true;
            for (int i = 0; i < N; i++) {
                if (i == tmp) continue;
                if (vis[i]) continue;
                mdis[i] = MIN(mdis[i], dis[tmp][i]);
            }
            tmp = find();
        }

        printf("The highest possible quality is 1/%d.\n", res);

    }
    return 0;
}
