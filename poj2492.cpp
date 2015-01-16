// poj 2492
// 368K 797MS G++
// disjoint union problem
#include <cstdio>

#define MAXN 2000

int t, m, n, x, y, rx, ry, pa[MAXN], rk[MAXN], cnt;
bool flag;

int find_union(int a)
{
    if (pa[a] != a) {
        int tmp = find_union(pa[a]);
        rk[a] *= rk[pa[a]];
        pa[a] = tmp;
    }
    return pa[a];
}

void merge_union(int a, int b, int ra, int rb)
{
    pa[rb] = ra;
    rk[rb] *= -rk[b] * rk[a];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    cnt = 0;
    while (t-- > 0) {
        flag = true;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) { pa[i] = i; rk[i] = 1; }
        while (m-- > 0) {
            scanf("%d %d", &x, &y);
            if (!flag) continue;
            x--, y--;
            rx = find_union(x);
            ry = find_union(y);
            if (rx != ry) merge_union(x, y, rx, ry);
            else if (rk[x] == rk[y]) flag = false;
        }

        if (flag)
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", ++cnt);
        else
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", ++cnt);
    }

    return 0;
}
