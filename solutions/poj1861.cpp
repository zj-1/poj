// poj 1861
// 580K 94MS G++
// kruskal MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 1000
#define MAXM 15000

struct pair {
    int x, y;
};
struct pair s[MAXM];

struct edge {
    int x, y, dis;
};
struct edge e[MAXM];

int cmp(const void *a, const void *b)
{
    return (*(struct edge *) a).dis - (*(struct edge *) b).dis;
}

int pa[MAXN + 1], cnt, k;

int find_union(int a)
{
    if (pa[a] != a) {
        pa[a] = find_union(pa[a]);
    }
    return pa[a];
}

int N, M, maxl;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    maxl = -1;
    cnt = k = 0;
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
            maxl = MAX(maxl, e[t].dis);
            s[k].x = e[t].x;
            s[k].y = e[t].y;
            cnt++; k++;
        }
        if (cnt == N - 1) break;
    }

    printf("%d\n%d\n", maxl, k);
    for (int i = 0; i < k; i++)
        printf("%d %d\n", s[i].x, s[i].y);

    return 0;
}

