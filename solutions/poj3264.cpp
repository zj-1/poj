// poj 3264
// 1400K 3407MS G++
// segment tree
#include <cstdio>
#include <cstring>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN (1 << 16)

int a[MAXN << 1], b[MAXN << 1], N, Q, x, y, minx, maxx;

void init()
{
    for (int i = 0; i < N; i++) {
        scanf("%d", a + MAXN + i);
        b[MAXN + i] = a[MAXN + i];
    }
    for (int i = MAXN - 1; i > 0; i--) {
        a[i] = MAX(a[i * 2], a[i * 2 + 1]);
        b[i] = MIN(b[i * 2], b[i * 2 + 1]);
    }
}

void rmq(int idx, int rl, int rr, int ql, int qr)
{
    if (ql > qr) return;
    if (rl == ql && rr == qr) {
        maxx = MAX(maxx, a[idx]);
        minx = MIN(minx, b[idx]);
    } else {
        int mid = (rl + rr) / 2;
        rmq(idx * 2, rl, mid, ql, MIN(mid, qr));
        rmq(idx * 2 + 1, mid + 1, rr, MAX(mid + 1, ql), qr);
    }
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &Q);
    init();

    while (Q-- > 0) {
        scanf("%d %d", &x, &y);
        maxx = -1;
        minx = INT_MAX;
        rmq(1, 1, MAXN, x, y);
        printf("%d\n", maxx - minx);
    }
    return 0;
}
