// poj 2231
// 440K 32MS G++
// dp
// use 64-bit integer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 10000

int N, i;
long long res, tmp;
int data[MAXL];

int cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d", data + i);

    res = 0;

    qsort(data, N, sizeof(int), cmp);

    tmp = 0;
    for (i = 1; i < N; i++) {
        // take care of overflowing
        tmp += i * (long long) (data[i] - data[i - 1]);
        res += tmp;
    }

    tmp = 0;
    for (i = N - 2; i >= 0; i--) {
        tmp += (N - 1 - i) * (long long) (data[i + 1] - data[i]);
        res += tmp;
    }

    printf("%I64d\n", res);
    return 0;
}
