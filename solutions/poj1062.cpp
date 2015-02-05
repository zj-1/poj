// poj 1062
// 380K 47MS G++
// bellman ford
// enumerate the possible range of level
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100

int N, M, P, L, X, T, V, cnt, u, v, w;
int lv[MAXN], pr[MAXN], minw[MAXN], minl[MAXN], maxl[MAXN], res;

typedef struct {
    int u, v, w;
} node;
node e[MAXN * MAXN];

int bford(int t)
{
    int res = INT_MAX; bool flag;
    memset(minw, 0x3f, sizeof(minw));
    minw[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        flag = false;
        for (int j = 0; j < cnt; j++) {
            u = e[j].u; v = e[j].v; w = e[j].w;
            if (lv[v] < t || lv[v] > t + M) continue;
            if (lv[u] < t || lv[u] > t + M) continue;
            if (minw[u] + w < minw[v]) {
                minw[v] = minw[u] + w;
                flag = true;
            }
        }
        if (flag) break;
    }

    for (int i = 0; i < N; i++) {
        res = MIN(res, pr[i] + minw[i]);
    }

    return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &M, &N);

    cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &P, &L, &X);
        pr[i] = P; lv[i] = maxl[i] = minl[i] = L;
        for (int j = 0; j < X; j++) {
            scanf("%d %d", &T, &V);
            e[cnt].u = i; e[cnt].v = T - 1; e[cnt].w = V;
            cnt++;
        }
    }

    res = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (abs(lv[i] - lv[0]) <= M) {
            res = MIN(bford(lv[i]), res);
        }
    }
    printf("%d\n", res);

    return 0;
}
