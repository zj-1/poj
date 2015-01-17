// poj 1703
// 1476K 641MS G++
// disjoint set problem
// merge all already-described member into one union, and use rank[] to describe
// their relation.
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 100000

int t, N, M, x, y, pa[MAXN], rank[MAXN];
char c;

void merge_union(int a, int b, int ra, int rb)
{
    pa[rb] = ra;
    rank[rb] = (rank[a] - rank[b] + 5) % 2;
}

int find_union(int a)
{
    if (pa[a] != a) {
        int tmp = pa[a];
        pa[a] = find_union(pa[a]);
        rank[a] = (rank[tmp] + rank[a]) % 2;
    }
    return pa[a];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) { pa[i] = i; rank[i] = 0; }
        for (int i = 0; i < M; i++) {
            // take care of the input
            scanf("\n%c %d %d", &c, &x, &y);
            x--, y--;
            int rx = find_union(x);
            int ry = find_union(y);
            if (c == 'D') {
                merge_union(x, y, rx, ry);
            } else {
                if(rx != ry) {
                    printf("Not sure yet.\n");
                } else if (rank[x] == rank[y]) {
                    printf("In the same gang.\n");
                } else {
                    printf("In different gangs.\n");
                }
            }
        }
    }

    return 0;
}
