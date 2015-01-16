// poj 2385
// 384K 0MS G++
// dp
#include <climits>
#include <cstdio>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MAXT 1000
#define MAXW 30
#define TREE 2

int dp[TREE][MAXW + 1], T, W, tmp, i, res;

inline int fun(int n)
{
    return n == 1 ? 0 : 1;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &T, &W);

    while (T-- > 0) {
        scanf("%d", &tmp);
        dp[tmp - 1][0]++;
        for (i = W; i > 0; i--) {
            if (dp[tmp - 1][i] == 0 && dp[fun(tmp - 1)][i - 1] == 0)
                continue;
            dp[tmp - 1][i] =
                MAX(dp[tmp - 1][i], dp[fun(tmp - 1)][i - 1]) + 1;
        }
    }

    res = INT_MIN;
    for (i = 0; i <= W; i++)
        res = MAX(res, MAX(dp[0][i], dp[1][i]));

    printf("%d\n", res);

    return 0;
}
