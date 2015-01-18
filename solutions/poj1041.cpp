// poj 1041
// 748K 79MS G++
// Euler Circuits
// it's strange that the commented part got WA on poj.
// if there is some point with odd number degree in the grapf, then no solution
// for this case.
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXS 1994
#define MAXJ 44

int ne, nv, g[MAXJ][MAXS], degree[MAXJ], st[MAXS], top;
bool vis[MAXS];

void euler(int x)
{
    for (int i = 0; i <= ne; i++) {
        if (!vis[i] && g[x][i] >= 0) {
            vis[i] = true;
            // !! WA !!
            // st[top] = i; top++;
            // euler(g[x][i]);
            euler(g[x][i]);
            st[top] = i; top++;
        }
    }
}

void print()
{
    while (top > 0) {
        printf("%d ", st[top - 1] + 1);
        top--;
    }
    // !! WA !!
    // for (int i = 0; i < top; i++)
    //     printf("%d ", st[i]);
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int s, x, y, z; bool flag;
    while (scanf("%d %d", &x, &y) && x != 0 && y != 0) {
        ne = nv = top = 0;
        flag = true;
        memset(vis, false, sizeof(vis));
        memset(g, 0xff, sizeof(g));
        memset(degree, 0, sizeof(degree));
        scanf("%d", &z);

        x--, y--, z--;
        nv = MAX(nv, MAX(x, y)), ne = MAX(ne, z);
        s = MIN(x, y);
        degree[x]++, degree[y]++;
        g[x][z] = y, g[y][z] = x;

        while (scanf("%d %d", &x, &y) && x != 0 && y != 0) {
            scanf("%d", &z);
            x--, y--, z--;
            nv = MAX(nv, MAX(x, y)), ne = MAX(ne, z);
            degree[x]++, degree[y]++;
            g[x][z] = y, g[y][z] = x;
        }

        for (int i = 0; i <= nv; i++) {
            if (degree[i] % 2 == 1) {
                flag = false; break;
            }
        }

        if (!flag) {
            printf("Round trip does not exist.\n");
        } else {
            euler(s); print();
        }
    }

    return 0;
}
