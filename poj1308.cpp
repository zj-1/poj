// poj 1308
// 776K 0MS G++
// disjoint set problem
// lots of details

/*
input:
0 0
6 8  5 3  5 2  6 4 5 6  0 0
8 1  7 3  6 2  8 9  7 5 7 4  7 8  7 6  0 0
3 8  6 8  6 4 5 3  5 6  5 2  0 0
1 2 1 2 0 0
1 1 0 0
1 2 2 3 4 5 0 0
1 2 2 1 0 0
1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 1 0 0
-1 -1

output:
Case 1 is a tree.
Case 2 is a tree.
Case 3 is a tree.
Case 4 is not a tree.
Case 5 is not a tree.
Case 6 is not a tree.
Case 7 is not a tree.
Case 8 is not a tree.
Case 9 is not a tree.
*/
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 30001

int pa[MAXN];

int find_union(int a)
{
    if (pa[a] != a)
        pa[a] = find_union(pa[a]);

    return pa[a];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int cnt = 0, x, y, rx, ry, max, tmp;
    bool tree;
    while (true) {
        max = -1;
        tree = true;
        for (int i = 0; i < MAXN; i++)
            pa[i] = i;
        scanf("%d %d", &x, &y);
        if (x < 0 || y < 0)
            break;

        while (x != 0 && y != 0) {
            if (!tree) {
                scanf("%d %d", &x, &y);
                continue;
            }

            max = MAX(MAX(max, x), y);
            if (x == y) { tree = false; continue; }

            rx = find_union(x - 1);
            ry = find_union(y - 1);
            if (ry != y - 1 || rx == ry) tree = false;
            else pa[ry] = rx;

            scanf("%d %d", &x, &y);
        }

        if (tree) {
            tmp = -1;
            for (int i = 0; i < max; i++) {
                if (pa[i] == i) continue;
                int ro = find_union(i);
                if (tmp == -1) tmp = ro;
                else if (tmp != ro) { tree = false; break; }
            }
        }

        if (tree)
            printf("Case %d is a tree.\n", ++cnt);
        else
            printf("Case %d is not a tree.\n", ++cnt);
    }

    return 0;
}
