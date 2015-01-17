// poj 1922
// 404K 0MS G++
// easy problem
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int N, i, a, b, ans, tmp;
    while (scanf("%d", &N) && N != 0) {
        ans = INT_MAX;
        for (i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            if (b < 0) continue;
            tmp = (int) ceil(4.5 / a * 3600 + b);
            if (ans > tmp) ans = tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}
