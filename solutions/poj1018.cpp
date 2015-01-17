// poj 1018
// 416K 16MS G++
// greedy problem
// find the minimum price at each bandwidth value
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXM 100
#define MAXB 1000

int t, n, t_pc, t_bw, i, j, m;
int dp[MAXB], dp_old[MAXB];
float res, tmp_max, tmp;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);

    while (t-- > 0) {
        memset(dp_old, 0x00, sizeof(dp_old));
        scanf("%d", &n);
        while (n-- > 0) {
            scanf("%d", &m);
            memset(dp, 0x3f, sizeof(dp));
            for (i = 0; i < m; i++) {
                scanf("%d %d", &t_bw, &t_pc);
                for (j = 0; j < t_bw; j++)
                    // greedy
                    dp[j] = MIN(dp[j], t_pc);
            }
            // update the price
            for (i = 0; i < MAXB; i++) dp_old[i] += dp[i];
        }

        res = 0.0;
        for (i = 0; i < MAXB; i++)
            res = MAX(res, (i + 1.0) / dp_old[i]);

        printf("%.3f\n", res);
    }

    return 0;
}
