// poj 2524
// 548K 344MS G++
// disjoint union problem
#include <cstdio>

#define MAXN 50000

int m, n, a, b, pa[MAXN], res;

int find_set(int a)
{
    if (pa[a] != a) pa[a] = find_set(pa[a]);
    return pa[a];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int x, y, cnt = 0;
    while (scanf("%d %d", &n, &m) && n != 0) {
        if (m == 0) { printf("%d\n", n); continue; }
        res = n;
        for (int i = 0; i < n; i++) pa[i] = i;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            a = find_set(x - 1); b = find_set(y - 1);
            if (a != b) { pa[b] = a; res--; }
        }
        printf("Case %d: %d\n", ++cnt, res);
    }

    return 0;
}

