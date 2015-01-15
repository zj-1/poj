// poj 1011
// 404K 16MS G++
// searching / dfs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 64

int n, len[MAXL], res, m;
bool used[MAXL];

int cmp(const void *a, const void *b)
{
    return (*(int *) b) - (*(int *) a);
}

bool dfs(int llen, int cnt, int sum)
{
    if (cnt == n) return true;

    if (sum == res) sum = 0;

    int tmp = -1;
    for (int i = 0; i < n; i++) {

        if (used[i]) continue;
        if (sum + len[i] > res) continue;

        // skip the following sticks with the same length as previous one, which
        // already failed the test.
        if (len[i] == tmp) continue;

        used[i] = true;
        if (dfs(llen, cnt + 1, sum + len[i]) == 1) return true;
        used[i] = false;
        tmp = len[i];

        // if it's the first or last chose one during certain trial, it's not
        // necessary to continue.
        if (sum == 0 || sum + len[i] == res) break;
    }

    return false;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) && n != 0) {
        m = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", len + i);
            m += len[i];
        }

        // use longer sticks first
        qsort(len, n, sizeof(int), cmp);

        for (res = len[0]; res <= m; res++) {
            if (m % res != 0)
                continue;
            memset(used, false, sizeof(used));
            if (dfs(res, 0, 0)) {
                printf("%d\n", res);
                break;
            }
        }

    }

    return 0;
}
