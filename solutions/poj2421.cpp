// poj 2421
// 584K 79MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 500

int N, Q, res, a, b, dis[MAXN][MAXN], mdis[MAXN];

int find()
{
    int m = INT_MAX, k = -1;
    for (int i = 0; i < N; i++) {
        if (m > mdis[i] && mdis[i] != 0) {
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
    res = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &dis[i][j]);

    scanf("%d", &Q);
    while (Q-- > 0) {
        scanf("%d %d", &a, &b);
        dis[a - 1][b - 1] = dis[b - 1][a - 1] = -1;
    }

    for (int i = 0; i < N; i++) mdis[i] = dis[0][i];
    int tmp = find();
    while (tmp != -1) {
        if (mdis[tmp] != -1) res += mdis[tmp];
        mdis[tmp] = 0;
        for (int i = 0; i < N; i++) {
            if (mdis[i] == 0)
                continue;
            mdis[i] = MIN(mdis[i], dis[tmp][i]);
        }
        tmp = find();
    }
    printf("%d\n", res);

    return 0;
}
