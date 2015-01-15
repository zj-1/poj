// poj 2442
// 424K 454MS G++
// use binary heap to maintain the $n$ smallest sums
// STL function make_heap(), heap_pop() and heap_push() could be useful

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 2000

int T, m, n, tmp, f;
int a[MAXN], b[MAXN], heap[MAXN];

int cmp(const void *a, const void *b)
{
    return (*(int *) a) - (*(int *) b);
}

void exchange(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void max_heap(int t)
{
    int l = (t << 1), r = (t << 1) + 1, lgr = t;
    if (l <= n && heap[l - 1] > heap[t - 1])
        lgr = l;
    if (r <= n && heap[r - 1] > heap[lgr - 1])
        lgr = r;
    if (lgr != t) {
        exchange(heap[t - 1], heap[lgr - 1]);
        max_heap(lgr);
    }
}

void make_heap(int t)
{
    for (int i = (t >> 1); i > 0; i--)
        max_heap(i);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++)
                scanf("%d", b + j);
            qsort(b, n, sizeof(int), cmp);
            for (int p = 0; p < n; p++)
                heap[p] = a[p] + b[0];
            make_heap(n);

            for (int p = 1; p < n; p++) {
                if (p != 1 && f != 1)
                    break;
                f = 0;
                for (int k = 0; k < n; k++) {
                    tmp = a[k] + b[p];
                    if (tmp < heap[0]) {
                        f = 1;
                        heap[0] = tmp;
                        max_heap(1);
                    }
                }
            }
            memcpy(a, heap, sizeof(a));
        }

        qsort(a, n, sizeof(int), cmp);
        printf("%d", a[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", a[i]);

        printf("\n");
    }

    return 0;
}
