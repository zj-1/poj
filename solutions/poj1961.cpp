// poj 1961
// 6064K 500MS G++
// kmp
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXN 1000000

int N, next[MAXN];
char w[MAXN + 1];

typedef struct {
    int x, y;
} node;
node res[MAXN];

int cmp(const void *a ,const void *b)
{
    return ((node *)a)->x - ((node *)b)->x;
}

void kmp(int n)
{
    int k = next[0] = -1;
    for (int i = 1; i < N; i++) {
        while (k > -1 && w[k + 1] != w[i]) { k = next[k]; }
        if (w[k + 1] == w[i]) { k++; }
        next[i] = k;
    }

    int p = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (next[i] == -1) continue;
        int t = i - next[i];
        if ((i + 1) % t == 0 && (i + 1) != t) {
            res[p].x = i + 1; res[p].y = (i + 1) / t; p++;
        }
    }

    qsort(res, p, sizeof(node), cmp);
    printf("Test case #%d\n", n);
    for (int i = 0; i < p; i++) {
        printf("%d %d\n", res[i].x, res[i].y);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int cnt = 1;
    while (scanf("%d", &N) && N != 0) {
        scanf("%s", w);
        kmp(cnt++);
    }

    return 0;
}
