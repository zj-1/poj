// poj 1182
// 788K 250MS G++
// Disjoint-set problem
// all already-described nodes are merged into one set, use rank array to note
// their relation (0, 1, or 2).

#include <stdio.h>

#define MAXN 50000

int N, K, res, t, x, y, p[MAXN];

// the distance between current and root node, the value of r[root] is
// meaningless, unless current set is merged into another. In this case, r[other
// nodes] should be updated, which is processed in find_set() routine.
int r[MAXN];

int find_set(int a)
{
    if (p[a] != a) {
        int tmp = p[a];
        p[a] = find_set(p[a]);
        // update the distance of current node
        r[a] = (r[a] + r[tmp]) % 3;
    }
    return p[a];
}

void union_set(int a, int b, int pa, int pb, int c)
{
    p[pb] = pa;
    // three nodes are linked as `b->rb->a'
    r[pb] = (r[a] - r[b] + 2 + c) % 3;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    res = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) { p[i] = i; r[i] = 0; }

    int px, py;
    while (K-- > 0) {
        scanf("%d %d %d", &t, &x, &y);
        x--, y--;
        if ((t == 2 && x == y) || x >= N || y >= N) {
            res++; continue;
        } else {
            px = find_set(x);
            py = find_set(y);
            if (t == 1 && px == py && r[x] != r[y]) {
                res++; continue;
            } else if (t == 2 && px == py && (r[x] + 1) % 3 != r[y]) {
                res++; continue;
            }
            union_set(x, y, px, py, t);
        }
    }

    printf("%d\n", res);

    return 0;
}
