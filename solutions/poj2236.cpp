// poj 2236
// 1376K 3063MS G++
// disjoint union problem
#include <cstdio>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 1001

int pa[MAXN], rk[MAXN], x[MAXN], y[MAXN];
bool dis[MAXN][MAXN], rpr[MAXN];

int find_union(int a) {
    if (pa[a] != a) {
        pa[a] = find_union(pa[a]);
    }
    return pa[a];
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int n, d, p, q, rp, rq, ri, tmp;
    char c;
    bool flag;
    scanf("%d %d", &n, &d);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", x + i, y + i);
        pa[i] = i;
        rpr[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            dis[i][j] = (tmp <= d * d);
        }
    }

    while (scanf("\n%c", &c) != EOF) {
        if (c == 'O') {
            scanf("%d", &p); p--;
            rpr[p] = true;
            rp = find_union(p);
            for (int i = 0; i < n; i++) {
                if (i == p) continue;
                ri = find_union(i);
                if (ri != rp && dis[MIN(p, i)][MAX(p, i)] && rpr[i]) {
                    pa[ri] = rp;
                }
            }
        } else if (c == 'S') {
            flag = true;
            scanf("%d %d", &p, &q); p--, q--;
            if (!rpr[p] || !rpr[q]) {
                flag = false;
            } else {
                rp = find_union(p);
                rq = find_union(q);
                if (rp != rq) flag = false;
            }

            if (flag) {
                printf("SUCCESS\n");
            } else {
                printf("FAIL\n");
            }
        }
    }

    return 0;
}
