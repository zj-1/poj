// poj 2593
// 1568K 204MS G++
// subsequence with maximum sum
// double direction
#include <cstdio>
#include <climits>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MAXL 100000

int N, res, i, tmp, max;
int data[MAXL], dp1[MAXL], dp2[MAXL];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &N) == 1 && N != 0) {

        for (i = 0; i < N; i++)
            scanf("%d", &data[i]);

        for (i = 0, tmp = 0, max = INT_MIN; i < N; i++) {
            tmp = MAX(tmp + data[i], data[i]);
            dp1[i] = max = MAX(tmp, max);
        }

        for (i = N - 1, tmp = 0, max = INT_MIN; i >= 0; i--) {
            tmp = MAX(tmp + data[i], data[i]);
            dp2[i] = max = MAX(max, tmp);
        }

        res = INT_MIN;
        for (i = 0; i < N - 1; i++)
            res = MAX((dp1[i] + dp2[i + 1]), res);

        printf("%d\n", res);
    }
    return 0;
}
