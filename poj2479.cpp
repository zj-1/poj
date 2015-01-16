// poj 2479
// 1372K 454MS G++
// subsequence with maximum sum
// dp
#include <cstdio>
#include <climits>
#include <cstring>

#define MAXL 100000
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int N, n, res, i;
int a[MAXL], b[MAXL], m1[MAXL], m2[MAXL];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);

    while (scanf("%d", &n) == 1 && n != 0) {

        m1[0] = m2[n - 1] = INT_MIN;

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        memset(b, 0, sizeof(b));
        for (i = 0; i < n; i++) {
            if (i == 0) {
                m1[i] = b[i] = a[i];
                continue;
            } else if (b[i - 1] >= 0)
                b[i] = b[i - 1] + a[i];
            else
                b[i] = a[i];
            m1[i] = MAX(b[i], m1[i - 1]);
        }

        memset(b, 0, sizeof(b));
        for (i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                m2[i] = b[i] = a[i];
                continue;
            } else if (b[i + 1] >= 0)
                b[i] = b[i + 1] + a[i];
            else
                b[i] = a[i];
            m2[i] = MAX(b[i], m2[i + 1]);
        }

        res = INT_MIN;
        for (i = 0; i < n - 1; i++) {
            res = MAX((m1[i] + m2[i + 1]), res);
        }

        printf("%d\n", res);
    }
    return 0;
}
