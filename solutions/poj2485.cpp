// poj 2485
// 780K 172MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 500

int N, t, res, dis[MAXN][MAXN], mdis[MAXN];

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

    scanf("%d", &t);
    while (t-- > 0) {

        res = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &dis[i][j]);

        for (int i = 0; i < N; i++) mdis[i] = dis[0][i];

        int tmp = find();
        while (tmp != -1) {
            res = MAX(mdis[tmp], res);
            mdis[tmp] = 0;

            for (int i = 0; i < N; i++) {
                if (mdis[i] == 0) continue;
                mdis[i] = MIN(mdis[i], dis[tmp][i]);
            }
            tmp = find();
        }

        printf("%d\n", res);
    }
    return 0;
}
