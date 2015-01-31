// poj 1823
// 1120K 4594MS G++
// segment tree with label
// cov = 1: all distributed
// cov = -1: all free
// cov = 0: different status for different nodes
#include <cstdio>
#include <cstring>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 16000

typedef struct {
    int l, r, ml, mr, len, cov;
} node;
node data[MAXN * 3];

int N, P;

void init(int u, int l, int r)
{
    data[u].cov = -1;
    data[u].l = l;
    data[u].r = r;
    data[u].ml = data[u].mr = data[u].len = r - l + 1;

    if (l != r) {
        int mid = (l + r) / 2;
        init(u * 2, l, mid);
        init(u * 2 + 1, mid + 1, r);
    }
}

void rmq(int u, int ql, int qr, int op)
{
    if (ql > qr || ql > data[u].r || qr < data[u].l) return;
    if (data[u].l == ql && data[u].r == qr) {
        if (data[u].cov != op) {
            data[u].cov = op;
            if (op == -1)
                data[u].ml = data[u].mr = data[u].len
                    = data[u].r - data[u].l + 1;
            else
                data[u].ml = data[u].mr = data[u].len = 0;
        }
        return;
    } else if (data[u].l != data[u].r) {
        if (data[u].cov != 0) { // fix child according to the label
            data[2 * u].cov = data[2 * u + 1].cov = data[u].cov;
            if (data[u].cov == -1) {
                data[2 * u].ml = data[2 * u].mr = data[2 * u].len
                    = data[2 * u].r - data[2 * u].l + 1;
                data[2 * u + 1].ml = data[2 * u + 1].mr = data[2 * u + 1].len
                    = data[2 * u + 1].r - data[2 * u + 1].l + 1;
            } else {
                data[2 * u].ml = data[2 * u].mr = data[2 * u].len = 0;
                data[2 * u + 1].ml = data[2 * u + 1].mr = data[2 * u + 1].len = 0;
            }
        }
        int mid = (data[u].l + data[u].r) / 2;
        rmq(u * 2, ql, MIN(mid, qr), op);
        rmq(u * 2 + 1, MAX(mid + 1, ql), qr, op);

        if (data[2 * u].cov == -1)
            data[u].ml = data[2 * u].len + data[2 * u + 1].ml;
        else
            data[u].ml = data[2 * u].ml;

        if (data[2 * u + 1].cov == -1)
            data[u].mr = data[2 * u + 1].len + data[2 * u].mr;
        else
            data[u].mr = data[2 * u + 1].mr;

        data[u].len = MAX(MAX(data[u * 2].len, data[2 * u + 1].len),
                data[2 * u].mr + data[2 * u + 1].ml);

        if (data[2 * u].cov == data[2 * u + 1].cov)
            data[u].cov = data[2 * u].cov;
        else
            data[u].cov = 0;
    }
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &P);
    init(1, 1, N);

    int x, a, b;
    while (P-- > 0) {
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d %d", &a, &b);
            rmq(1, a, a + b -1, 1);
        } else if (x == 2) {
            scanf("%d %d", &a, &b);
            rmq(1, a, a + b - 1, -1);
        } else if (x == 3) {
            printf("%d\n", data[1].len);
        }
    }

    return 0;
}
