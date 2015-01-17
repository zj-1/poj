// poj 1988
// 1012K 532MS G++
// disjoint set problem
// merge all already-described member into one union, and use rank[] to describe
// their relation. num[root] records the number of elements in the current set.
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 30001

int P, x, y, pa[MAXN], rank[MAXN], num[MAXN];
char c;

int find_union(int a)
{
    if (pa[a] != a) {
        int tmp = find_union(pa[a]);
        rank[a] += rank[pa[a]];
        pa[a] = tmp;
    }
    return pa[a];
}

void merge_union(int a, int b)
{
    int ra = find_union(a);
    int rb = find_union(b);

    if (ra != rb) {
        pa[ra] = rb;
        rank[ra] = num[rb];
        num[rb] += num[ra];
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    for (int i = 0; i < MAXN; i++) { pa[i] = i; rank[i] = 0; num[i] = 1; }
    scanf("%d", &P);
    while (P-- > 0) {
        // take care of the input
        scanf("\n%c", &c);
        if (c == 'M') {
            scanf("%d %d", &x, &y);
            merge_union(x - 1, y - 1);
        } else {
            scanf("%d", &x);
            find_union(x - 1);
            printf("%d\n", rank[x - 1]);
        }
    }

    return 0;
}
