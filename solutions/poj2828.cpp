// poj 2828
// 6028K 3454MS G++
// segment tree
#include <cstdio>
#include <cstring>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN (1 << 18)

typedef struct {
    int num, val;
} node;
node x[MAXN], t[MAXN * 2];
int N;

void init()
{
    for (int i = 0; i < MAXN; i++) { t[MAXN + i].num = 1; }
    for (int i = MAXN - 1; i > 0; i--) {
        t[i].num = t[i * 2].num + t[i * 2 + 1].num;
    }
}

void insert(int pos, int val)
{
    int u = 1;
    while (u < MAXN) {
        if (pos <= t[2 * u].num) {
            u = 2 * u;
        } else {
            pos -= t[2 * u].num;
            u = 2 * u + 1;
        }
    }
    t[u].val = val; t[u].num = 0;
    u /= 2;
    while (u > 0) { t[u].num--; u /= 2; }
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &N) != EOF) {
        init();

        for (int i = 0; i < N; i++) {
            scanf("%d %d", &(x[i].num), &(x[i].val));
        }

        for (int i = N - 1; i >= 0; i--) {
            insert(x[i].num + 1, x[i].val);
        }

        for (int i = 0; i < N; i++) {
            printf("%d ", t[MAXN + i].val);
        }
        printf("\n");
    }

    return 0;
}
