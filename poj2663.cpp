// poj 2663
// 384K 0MS G++
// dp
#include<cstdio>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int n, i, j, dp[16];
    dp[0] = 1;
    for (i = 1; i <= 15; i++) {
        dp[i] = 3 * dp[i - 1];
        for (j = 0; j <= i - 2; j++)
            dp[i] += 2 * dp[j];
    }
    while (scanf("%d", &n) && n != -1) {
        if (n % 2 == 1) printf("0\n");
        else printf("%d\n", dp[n / 2]);
    }
    return 0;
}
