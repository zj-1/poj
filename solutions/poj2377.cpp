// poj 2377
// 628K 32MS G++
// kruskal MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 1000
#define MAXM 20000

struct edge {
    int x, y, dis;
};
struct edge e[MAXM];

int cmp(const void *a, const void *b)
{
    return (*(struct edge *) b).dis - (*(struct edge *) a).dis;
}

int pa[MAXN + 1], cnt;

int find_union(int a)
{
    if (pa[a] != a) {
        pa[a] = find_union(pa[a]);
    }
    return pa[a];
}

int N, M, res;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    res = 0;
    cnt = 0;
    for (int i = 0; i <= N; i++) pa[i] = i;

    for (int i = 0; i < M; i++)
        scanf("%d %d %d", &(e[i].x), &(e[i].y), &(e[i].dis));
    qsort(e, M, sizeof(struct edge), cmp);

    for (int t = 0; t < M; t++) {
        int rx = find_union(e[t].x);
        int ry = find_union(e[t].y);
        if (rx == ry) continue;
        else {
            pa[ry] = rx;
            res += e[t].dis;
            cnt++;
        }
        if (cnt == N - 1) break;
    }

    if (cnt != N - 1) res = -1;

    printf("%d\n", res);

    return 0;
}
