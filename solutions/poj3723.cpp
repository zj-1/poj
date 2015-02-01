// poj 3723
// 1096K 422MS G++
// MST
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 20000
#define MAXE 50000

typedef struct {
    int u, v, w;
} node;
node e[MAXE];

int t, N, M, R, x, y, d, pa[MAXN], rk[MAXN];

int cmp(const void *a, const void *b)
{
    return ((node *) b)->w - ((node *) a)->w;
}

int find_union(int x)
{
    if (x != pa[x]) pa[x] = find_union(pa[x]);
    return pa[x];
}

int kruskal()
{
    int res = N * 10000, ru, rv, cnt = 0;

    for (int i = 0; i < N; i++) { pa[i] = i; rk[i] = 1; }

    qsort(e, M, sizeof(e[0]), cmp);
    for (int i = 0; i < M; i++) {
        ru = find_union(e[i].u);
        rv = find_union(e[i].v);
        if (ru != rv) {
            if (rk[ru] > rk[rv]) {
                pa[rv] = ru; rk[ru] += rk[rv];
            } else {
                pa[ru] = rv; rk[rv] += rk[ru];
            }
            res -= e[i].w; cnt++;
        }
        if (cnt == N - 1) break;
    }
    return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d %d", &N, &M, &R);
        for (int i = 0; i < R; i++) {
            scanf("%d %d %d", &x, &y, &d);
            e[i].u = x; e[i].v = N + y; e[i].w = d;
        }
        N = N + M; M = R;
        printf("%d\n", kruskal());
    }
    return 0;
}
