// poj 2245
// 404K 16MS G++
// easy problem
// dfs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXK 13
#define NUM 6

int k, data[MAXK], res[NUM];

int cmp(const void *a, const void *b)
{
    return (*(int *) a) - (*(int *) b);
}

void print()
{
    for (int i = 0; i < NUM - 1; i++)
        printf("%d ", res[i]);
    printf("%d\n", res[NUM - 1]);
}

void dfs(int n, int cnt)
{
    for (int i = n; i < k - 5 + cnt; i++) {
        res[cnt] = data[i];
        if (cnt == NUM - 1)
            print();
        else
            dfs(i + 1, cnt + 1);
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &k) && k != 0) {
        for (int i = 0; i < k; i++)
            scanf("%d", data + i);
        qsort(data, k, sizeof(int), cmp);
        dfs(0, 0);
        printf("\n");
    }

    return 0;
}
