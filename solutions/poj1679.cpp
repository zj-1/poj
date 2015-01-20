// poj 1679
// 456K 16MS G++
// kruskal MST
// Enumerate each edge in the MST, the regenerate the MST (excluding the current
// edge). If the cost of MST remains the same, then MST is not unique.
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100
#define MAXM 20000

struct edge {
    int x, y, dis;
};
struct edge e[MAXM];

int used_edge[MAXM];

int cmp(const void *a, const void *b)
{
    return (*(struct edge *) a).dis - (*(struct edge *) b).dis;
}

int pa[MAXN + 1];

int find_union(int a)
{
    if (pa[a] != a) {
        pa[a] = find_union(pa[a]);
    }
    return pa[a];
}

int N, M, res, t, res2, cnt, cnt2;
bool flag;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t-- > 0) {
        flag = false;
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
                used_edge[cnt] = t;
                pa[ry] = rx;
                res += e[t].dis;
                cnt++;
            }
            // if (cnt == N - 1) break;
        }

        for (int k = 0; k < cnt; k++) {
            res2 = 0;
            cnt2 = 0;
            for (int i = 0; i <= N; i++) pa[i] = i;

            for (int t = 0; t < M; t++) {
                if (t == used_edge[k]) continue;
                int rx = find_union(e[t].x);
                int ry = find_union(e[t].y);
                if (rx == ry) continue;
                else {
                    pa[ry] = rx;
                    res2 += e[t].dis;
                    cnt2++;
                }
            }
            if (cnt2 == cnt && res == res2) {
                flag = true;
                break;
            }
        }

        if (!flag)
            printf("%d\n", res);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
